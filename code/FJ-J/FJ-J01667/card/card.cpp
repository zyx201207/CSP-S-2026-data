#include <bits/stdc++.h>
using namespace std;
int n,a[5000000],m,ans[5000000],c[5000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("cart.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;i++)
		{
			c[i] = a[i];
		}
		for(int k = i-1;k <= n;k++)
		{
			c[k] = 0;
		}
		for (int k = i-1;k <= n;k++)
		{
			for (int v = 0;v <= n;v++)
			{
				if (c[v] == a[k])
				{
					for (int f = v+1;f <= n;f++)
					{
						c[f] = 0;
					}
				}
				else
				{
					c[k] = c[v];
				}
			}
		}
		for (int j = 1;j <= n;j++)
		{
			int o = c[j];
			ans[o]++;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
