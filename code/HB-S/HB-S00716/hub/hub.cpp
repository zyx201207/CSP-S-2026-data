#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int c,t,n,k,u,v,ans,dep[1000005],fa[1000005],l[1005][1005];
bool b[1000005],vis[1000005];
vector<int> e[1000005];
void dfs_ltk(int u,int fa)
{
	vis[u]=1;
	for(int i=0;i<(int)e[u].size();i++)
	{
		if(e[u][i]==fa||!b[e[u][i]])continue;
		dfs_ltk(e[u][i],u);
	}
}
void dfs(int i,int c)
{
	if(c>=k)
	{
		int cnt=0,s=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			if(b[i]&&!vis[i])
			{
				cnt++;
				dfs_ltk(i,0);
			}
		}
		if(cnt<=2)
		{
			for(int i=1;i<=n;i++)
			{
				if(b[i])continue;
				int minn=2147483647;
				for(int j=1;j<=n;j++)
				{
					if(b[j])
					{
						minn=min(minn,-dep[l[i][j]]*2+dep[i]+dep[j]);
					}
				}
				s=max(s,minn);
			}
			ans=min(ans,s);
		}
		return;
	}
	else if(i>n)
	{
		return;
	}
	b[i]=1;
	dfs(i+1,c+1);
	b[i]=0;
	dfs(i+1,c);
}
void dfs_dep(int u,int f)
{
	dep[u]=dep[f]+1;
	fa[u]=f;
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(v==f)continue;
		dfs_dep(v,u);
	}
}
int lca(int u,int v)
{
	while(dep[u]>dep[v])u=fa[u];
	while(dep[v]>dep[u])v=fa[v];
	while(u!=v)u=fa[u],v=fa[v];
	return u;
}
void solve()
{
	memset(l,0,sizeof(l));
	memset(dep,0,sizeof(dep));
	memset(fa,0,sizeof(fa));
	ans=2147483647;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		e[i].clear();
		b[i]=0;
	}
	for(int i=1;i<n;i++)
	{
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs_dep(1,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			l[i][j]=lca(i,j);
		}
	}
	dfs(1,0);
	cout << ans << "\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	if(c<=3)
	{
		while(t--)solve();
	}
	return 0;
}
