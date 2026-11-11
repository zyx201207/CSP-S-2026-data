#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans=1e9;
int g[15][15],vis[15],use[15];
int vis2[15];
int d(int i)
{
	if(vis[i])return 0;
	int ret=1e9;
	for(int j=1;j<=n;j++)
	{
		if(g[i][j] and !vis2)ret=min(ret,d(j));
	}
	return ret+1;
}
void dfs(int u,int sum,int flag,int fa)
{
	use[u]=1;
	cout<<u<<endl;
	if(sum>k)
	{
		int tmp=-1;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				memset(vis2,0,sizeof vis2);
				tmp=max(tmp,d(i));
			}
		}
		ans=min(ans,tmp);
		return ;
	}
	for(int j=1;j<=n;j++)
	{
		if(j==fa)continue;
		if(g[u][j] and !use[j])
		{
			dfs(j,sum,0,u);
			if(!flag)
			{
				vis[u]=1;
				dfs(j,sum+1,1,u);
				vis[u]=0;
			}
		}
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u][v]=g[v][u]=1;
	}
	dfs(1,0,0,0);
	cout<<ans<<"\n";
}
int main()
{
	freopen("hub1.in","r",stdin);
	//freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
}
