#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m,a[100000],sum[100000][100000];
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		sum[i][1] = a[i];
		for (int j = i+1;j <= n;j++)
		{
			for (int z = 1;z <= j;z++)
			{
				if (a[j] == a[z])
				{
					for (int h = 1; h < j;h++)
					{
						sum[i][h] = 0;
					}
				}
				else
				{
					sum[i][j] = z;
				}
			}
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (sum[i][j] == '1')
			{
				cout << i << " ";
			}
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (sum[i][j] == '2')
			{
				cout << i << " ";
			}
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (sum[i][j] == '3')
			{
				cout << i << " ";
			}
		}
	}
	return 0;
} 
