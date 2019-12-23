/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:11:10 by thalfemp          #+#    #+#             */
/*   Updated: 2019/11/26 18:05:04 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
void BresenhamFloat(int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr);
void drawx(int x, int x1, int y, void *mlx_ptr, void *win_ptr);
void drawy(int y, int y1, int x, void *mlx_ptr, void *win_ptr);

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * (-1));
	}
	else
	{
		if (nb >= 10)
			ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

int deal_key(int key, void *ptr)
{
	write(1, "\n", 1);
	ft_putchar('X');
	write(1, "\n", 1);
	ft_putnbr(key);
	return (0);
}

void rectangle(int left, int top, int right, int bottom, void *mlx_ptr, void *win_ptr)
{
	drawx(left, right, top, mlx_ptr, win_ptr);
	drawy(top, bottom, right,  mlx_ptr, win_ptr);
	drawx(right, left, bottom, mlx_ptr, win_ptr);
	drawy(bottom, top, left,  mlx_ptr, win_ptr);
}

void drawx(int x, int x1, int y, void *mlx_ptr, void *win_ptr)
{
	if (x < x1)
	{
		while (x != x1)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
			x++;
		}
	}
	else
	{
		while (x != x1)
		{
			 mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
			 x--;
		}
	}
}

void drawy(int y, int y1, int x, void *mlx_ptr, void *win_ptr)
{
	if (y < y1)
	{
		while (y != y1)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
			y++;
		}
	}
	else
	{
		while (y != y1)
		{
			 mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
			 y--;
		}
	}
}




void drawCircle(int xc, int yc, int x, int y, void *mlx_ptr, void *win_ptr)
{
	mlx_pixel_put(mlx_ptr, win_ptr, xc+x, yc+y, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, xc-x, yc+y, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, xc+x, yc-y, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, xc-x, yc-y, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, xc+y, yc+x, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, xc-y, yc+x, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, xc+y, yc-x, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, xc-y, yc-x, 0xFF0000);
}

void circleBres(int xc, int yc, int r, void *mlx_ptr, void *win_ptr)
{
	int x = 0, y = r;
	int d = 3 - 2 * r;
	
	drawCircle(xc, yc, x, y, mlx_ptr, win_ptr);
	while (y >= x)
 	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		drawCircle(xc, yc, x, y, mlx_ptr, win_ptr);
	 }
}

void BresenhamFloat(int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr)
{
	int x = x1;
	int y = y1;
	int dx;
	int dy;
	float e;
	
	dx = x2 - x1;
	dy = y2 - y1;
	e = ((float)dy/(float)dx);
	e -= 0.5;
	for (int i = 1; i <= dx; i++)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
		while (e >= 0)
		{
			y = y + 1;
			e--;
		}
		x = x + 1;
		e = e + (float)dy/(float)dx;
	}
}

void pyrimid(void *mlx_ptr, void *win_ptr)
{
	BresenhamFloat(300, 150, 460, 150, mlx_ptr, win_ptr);
	BresenhamFloat(300, 150, 380, 50, mlx_ptr, win_ptr);
	BresenhamFloat(460, 150, 380, 50, mlx_ptr, win_ptr);
	BresenhamFloat(300, 150, 380, 110, mlx_ptr, win_ptr);
	BresenhamFloat(460, 150, 380, 110, mlx_ptr, win_ptr);
	BresenhamFloat(380, 50, 380, 110, mlx_ptr, win_ptr);
}

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	int x;
	int y;
	int r;

	x = 250;
	y = 250;
	r = 60;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFF0000);
	rectangle(100, 200, 300, 300, mlx_ptr, win_ptr);
	rectangle(150, 250, 350, 350, mlx_ptr, win_ptr);
	BresenhamFloat(100, 200, 150, 250, mlx_ptr, win_ptr);
	BresenhamFloat(300, 300, 350, 350, mlx_ptr, win_ptr);
	BresenhamFloat(100, 300, 150, 350, mlx_ptr, win_ptr);
	BresenhamFloat(300, 200, 350, 250, mlx_ptr, win_ptr);
	//pyrimid( mlx_ptr, win_ptr);
	//circleBres(x, y, r, mlx_ptr, win_ptr);
	/*while (x < 400)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, 200, 0xFF0000);
		x++;
	}
	while (y < 400)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
		y++;
	}
	mlx_string_put(mlx_ptr, win_ptr, 250, 250, 0xFFFF00, "hello");*/
	mlx_key_hook(win_ptr, deal_key, (void*)0);
	mlx_loop(mlx_ptr);
}
