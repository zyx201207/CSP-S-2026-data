#include <bits/stdc++.h>
using namespace std;
int a[214514];
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	if(m == 1)
	{
		int maxn = -9999;
		for(int i = 1;i <= n;i ++)
		{
			maxn = max(a[i],maxn);
		}
		cout << maxn;
	}
	else if(m == 2)
	{
		int maxn = -9999;
		for(int i = 1;i < n;i ++)
		{
			for(int j = i + 1;j <= n;j ++)
			{
				maxn = max(maxn,a[i] & a[j]);
			}
		}
		cout << maxn;
	}
	else if(m == n)
	{
		long long sum = a[1];
		for(int i = 2;i <= n;i ++)
		{
			sum = sum & a[i];
		}
		cout << sum;
	}
	else if(m - 1 == n)
	{
		int maxn = 0;
		for(int i = 1;i <= n;i ++)
		{
			bool flag = 1;
			int sum = 0;
			for(int j = 1;j <= n;j ++)
			{
				if(j == i)
				{
					continue;
				}
				if(flag)
				{
					flag = 0;
					sum = a[j];
				}
				else
				{
					sum = sum & a[j];
				}
			}
			maxn = max(sum,maxn);
		}
		cout << maxn;
	}
	else if(m == 3) 
	{
		int maxn = -9999;
		for(int i = 1;i < n - 1;i ++)
		{
			for(int j = i + 1;j < n;j ++)
			{
				for(int k = j + 1;k <= n;k ++)
				{
					maxn = max(maxn,a[i] & a[j] & a[k]);
				}
			}
		}
		cout << maxn;
	}
	else if(m == 4) 
	{
		int maxn = -9999;
		for(int i = 1;i < n - 2;i ++)
		{
			for(int j = i + 1;j < n - 1;j ++)
			{
				for(int k = j + 1;k < n;k ++)
				{
					for(int h = k + 1;k <= n;h ++)
					{
						maxn = max(maxn,a[i] & a[j] & a[k] & a[h]);
					}
				}
			}
		}
		cout << maxn;
	}
	else if(m == 5)
	{
		int maxn = -9999;
		for(int i = 1;i < n - 3;i ++)
		{
			for(int j = i + 1;j < n - 2;j ++)
			{
				for(int k = j + 1;k < n - 1;k ++)
				{
					for(int h = k + 1;k < n;h ++)
					{
						for(int u = h + 1;u <= n;u ++)
						{
							maxn = max(maxn,a[i] & a[j] & a[k] & a[h] & a[u]);
						}
					}
				}
			}
		}
		cout << maxn;
	}
	return 0;
}

