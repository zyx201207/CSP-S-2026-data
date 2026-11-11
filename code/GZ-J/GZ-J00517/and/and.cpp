//GZ-J00517，石浩辰 ，北京师范大学贵阳附属中学
#include <bits/stdc++.h>
using namespace std;
int n , m , a[100002] , b , c = 1 , d , e[100002];
int max = 0 , k , r , s;
void g(int i)
{
	c = 1;
	while (a[i] > 0)
	{
		b = a[i] % 2;
		a[i] = (a[i] - b) / 2;
		e[i] += c * b;
		c *= 10;
	}
}
void j()
{
	for (int i = n ; i >= 1 ; i--)
	{
		for (int j = 1 ; j <= i ; j++)
		{
			int p = a[j];
			if (a[j] < a[j + 1])
			{
				a[j] = a[j + 1];
				a[j + 1] = p; 
			}
		}
	}
}
void l(int i)
{
	c = 1;
	while (e[i] > 0 && e[i + 1] > 0)
	{
		r = e[i] % 10 , s = e[i + 1] % 10;
		if (r == 1 && s == 1)  e[i + 1] = 1;
		else e[i + 1] = 0;
	}
}
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	int h = 1;
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	j();
	for (int i = 1 ; i <= m ; i++)
	{
		g(i);
	}
	for (int i = 3 ; i <= m ; i++)
	{
		l(i);
	}
    while (e[m] > 0)
    {
    	k += (e[m] % 10) * h;
    	e[m] = e[m] / 10 , h = h * 2;
	}
	cout << k;
	return 0;
}
