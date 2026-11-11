#include<bits/stdc++.h>
using namespace std;
long long n,a[100009],maxn=-1000009,m,vis[100009];
void dfs(long long now,long long depth)
{
	long long maxm=-1000009,maxp=0;
	for(long long i=1;i<=n;i++)
	{
		if(vis[i]==1) continue;
		if(maxm<now&a[i])
		{
			maxm=now&a[i];
			maxp=i;
		}
	}
	vis[maxp]=1;
	if(depth==m)
	{
		maxn=max(maxn,maxm);
		return;
	}
	dfs(maxm,depth+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(a[i],1);
	}
	cout<<maxn;
	return 0;
}

