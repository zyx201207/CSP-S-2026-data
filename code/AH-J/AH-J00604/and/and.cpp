#include "bits/stdc++.h" 
long long ans = 0,x,y,a[100001],b[100001];
void dfs(long long n,long long u)
{
	if (n == x+1)
	{
		if (u != y) return;
		bool flag = true;
		long long s;
		for (int i = 1;i <= x;i++)
		{
			if (b[i] == 1)
			{
				if (flag)
				{
					s = a[i];
					flag = false;
				}
				s &= a[i];
			}
		}
		ans = std::max(s,ans);
		return ;
	}
	b[n] = 0;
	dfs(n+1,u);
	b[n] = 1;
	dfs(n+1,u+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::cin >> x >> y;
	for (int i = 1;i <= x;i++)
	{
		std::cin >> a[i];
	}
	if (y == 1)
	{
		long long maxn = -1e9;
		for (long long i = 1;i <= x;i++)
		{
			maxn = std::max(maxn,a[i]);
		}
		std::cout << maxn;
		return 0;
	} 
	if (y == 2)
	{
		long long maxn = -1e9;
		for (long long i = 1;i < x;i++)
		{
			for (long long j = i+1;j <= x;j++)
			{
				maxn = std::max(a[i]&a[j],maxn);
			}
		}
		std::cout << maxn;
		return 0;
	}
	dfs(1,0);
	std::cout << ans;
	return 0;
}
