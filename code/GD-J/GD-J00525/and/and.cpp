#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200100];
int vis[200100] = {0};
long long mmax = 0;
void dfs(int deep,long long sum)
{
	if(deep == m)
	{
		mmax = max(mmax,sum);
		return ;
	}
	for(int i = 0;i < n;i++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			dfs(deep + 1,(sum & a[i]));
			vis[i] = 0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	int maxn = 0;
	long long ans = 0;
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		maxn = max(maxn,a[i]);
		if(i == 0)
		{
			ans = a[i];
		}
		else
		{
			ans &= a[i];
		}
	}
	if(m == 1)
	{
		printf("%d",maxn);
		return 0;
	}
	if(m == n)
	{
		printf("%lld",ans);
		return 0;
	}
	if(n <= 2000 && m == 2)
	{
		for(int i = 0;i < n;i++)
		{
			long long temp = a[i];
			for(int j = 0;j < n;j++)
			{
				if(i != j)
				{
					mmax = max(mmax,(temp & a[j]));
				}
			}
		}
		printf("%lld",mmax);
		return 0;
	}
	for(int i = 0;i < n;i++)
	{
		dfs(0,a[i]);
		vis[i] = 1;
	}
	printf("%lld",mmax);
	return 0;
}
