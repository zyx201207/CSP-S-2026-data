#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ma=0,a[2003],dp[2003][2003];
bool vis[2003];
void dfs(int mm,long long nu)
{
	if(mm==m)
	{
		ma=max(ma,nu);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		dfs(mm+1,nu&a[i]);
		vis[i]=0;
	}
	
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
		dfs(1,a[i]);
		vis[i]=0;	
	}
	printf("%lld",ma);
	return 0;
}
