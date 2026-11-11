#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[1000000],b[1000000],c[1000000];
	int d;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		b[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		c[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			d = 1;
			for (int k = 0; b[k] > 0; k++)
			{
				if (a[j] == a[k])
				{
					for (int r = k + 1; b[r] > 0; r++)
					{
						b[r] = 0;
					}
					d = 0;
					break;
				}
			}
			if (d == 1)
			{
				for (int r = 0; r < n; r++)
				{
					if (b[r] == 0)
					{
						b[r] = a[j];
						break;
					}
				}
			}
		}
		for (int j = 0; b[j] > 0; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (b[j] == k + 1)
				{
					c[k] = c[k] + 1;
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			b[j] = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cout << c[i];
	}
	return 0;
}
