#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int ans = 1;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(m == n)
	{
		for(int i = 1;i <= n;i++)
		{
			ans &= a[i];
		}
	}
	else if(m == 1)
	{
		int maxx = 0;
		for(int i = 1;i <= n;i++)
		{
			int x = a[i];
			maxx = max(maxx,x);
		}
		ans = maxx;
	}
	else if(m == 2)
	{
		int maxx = 0,x;
		for(int i = 1;i < n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				x = a[i] & a[j];
				maxx = max(maxx,x);
			}
		}
		ans = maxx;
	}
	else if(m == 3)
	{
		int maxx = 0,x;
		for(int i = 1;i < n - 1;i++)
		{
			for(int j = i + 1;j < n;j++)
			{
				for(int l = j + 1;l <= n;l++)
				{
					x = a[i] & a[j] & a[l];
					maxx = max(maxx,x);
				}
			}
		}
		ans = maxx;
	}
	else if(m == 4)
	{
		int maxx = 0,x;
		for(int i = 1;i < n - 2;i++)
		{
			for(int j = i + 1;j < n - 1;j++)
			{
				for(int l = j + 1;l < n;l++)
				{
					for(int k = l + 1;k <= n;k++)
					{
						x = a[i] & a[j] & a[l];
						maxx = max(maxx,x);
					}
				}
			}
		}
		ans = maxx;
	}
	else if(m == n - 1)
	{
		int maxx = 0,x = 1;
		for(int i = 1;i <= n;i++)
		{
			x = 1;
			for(int j = 1;j <= n;j++)
			{
				if(j == i)
				{
					continue;
				}
				x &= a[j];
			}
			maxx = max(maxx,x);
		}
		ans = maxx;
	}
	cout << ans;
	return 0;
}
