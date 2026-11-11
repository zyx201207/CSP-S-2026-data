#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans = 0,b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		int c[500005];
		for (int ii = 1;ii <= n;ii++)
		{
			c[ii] = a[ii];
		}
		for (int j = i;j <= n;j++)
		{
			int flag = 0;
			for (int k = 1;k <= n;k++)
			{
				if (c[k] == a[j])
				{
					for (int l = k + 1;l <= n;l++)
					{
						c[l] = 0;
					}
					flag = 1;
				}
				else continue;
			}
			if (flag == 0)
			{
				c[j] = a[j];
			}
		}
		for (int iii = 1;iii <= n;iii++)
		{
			b[c[iii]]++;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << b[i] << ' ';
	}
	return 0;
}
