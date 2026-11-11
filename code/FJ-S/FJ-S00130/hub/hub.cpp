#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int v,w;
};
vector<int> e[100005];
int c,t,n,k;
int f[100005][30],depth[100005];
bool vis[100005];
void dfs1(int u,int dep)
{
	depth[u]=dep;
	for(int i=0;i<=e[u].size();i++)
	{
		int v=e[u][i];
		if(!vis[v])
		{
			f[v][0]=u;
			vis[v]=1;
			dfs1(v,dep+1);
			vis[v]=0;
		}
	}
}
void dfs2(int k)
{
	for(int i=n;i>=1;i--)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs2(k-1);
			vis[i]=0;
		}
	}
}
void prep()
{
	for(int i=1;i<=25;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[j][i]=f[f[j][i-1]][i-1];
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs1(1,1);
		prep();
		memset(vis,0,sizeof(vis));
		dfs2(k);
		
	}
	return 0;
}
