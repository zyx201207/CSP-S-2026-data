#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,ans=1e18,a[35],use[35],vis[35];
vector<int>edge[35];
void dfs(int u,int fa)
{
	vis[u]=1;
	for(int v:edge[u])
	{
		if(!use[v])continue;
		if(v==fa)continue;
		dfs(v,u);
	}
}
int len(int u,int fa,int v)
{
	if(u==v)return 0;
	int ans=0;
	for(int vv:edge[u])
	{
		if(vv==fa)continue;
		ans=max(ans,len(vv,u,v));
	}
	return ans+1;
}
void dfs2(int dep,int now)
{
	if(dep==k+1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++)
			if(!vis[i])cnt++,dfs(i,0);
		if(cnt>2)return;
		int maxx=0;
		for(int i=1;i<=k;i++)
		{
			int minn=1e18;
			for(int j=1;j<=k;j++)
				minn=min(minn,len(i,0,j));
			maxx=max(maxx,minn);
		}		
		ans=min(ans,maxx);
	}
	for(int i=now+1;i<=n;i++)
		use[dep]=i,dfs2(dep+1,i);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(int u,v,i=1;i<n;i++)
			scanf("%lld%lld",&u,&v),
			edge[u].push_back(v),
			edge[v].push_back(u);
		dfs2(1,0);
		printf("%lld",ans);
	}
}
