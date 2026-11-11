#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,fa[100005][20],dep[100005],p[200005],vis[200005],mn[200005],ans;
vector<int> g[1000005];
void dfs(int x,int f)
{
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for (int i=1;i<=18;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=0;i<g[x].size();i++)
		if(g[x][i]!=f)
			dfs(g[x][i],x);
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for (int i=18;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)
		return x;
	for (int i=18;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void tian(int x)
{
	vis[x]=1;
	for (int i=0;i<g[x].size();i++)
		if(p[g[x][i]]&&!vis[g[x][i]])
			tian(g[x][i]);
}
void dfs2(int x,int cnt)
{
	if(x>n)
	{
		if(cnt==k)
		{
			int tot=0;
			for (int i=1;i<=n;i++)
				vis[i]=0;
			for (int i=1;i<=n;i++)
				if(p[i]&&!vis[i])
					tian(i),tot++;
			if(tot<=2)
			{
				for (int i=1;i<=n;i++)
					mn[i]=1e9;
				for (int i=1;i<=n;i++)
					for (int j=1;j<=n;j++)
						if(p[j])
							mn[i]=min(mn[i],dep[i]+dep[j]-2*dep[lca(i,j)]);
				int mx=0;
				for (int i=1;i<=n;i++)
					mx=max(mx,mn[i]);
				ans=min(ans,mx);
			}
		}
		return;
	}
	p[x]=0;
	dfs2(x+1,cnt);
	p[x]=1;
	dfs2(x+1,cnt+1);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for (int i=1;i<=n;i++)
			g[i].clear();
		ans=1e9;
		for (int i=1,x,y;i<n;i++)
			cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
		dfs(1,0);
		dfs2(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
