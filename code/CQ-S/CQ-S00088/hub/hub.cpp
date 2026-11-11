#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,ans=INT_MAX,dep[100001],fa[100001],son[100001],siz[100001],top[100001];
vector<int> to[100001];
bool vis[100001],viss[100001];
void dfs1(int x,int f)
{
	dep[x]=dep[f]+1;
	siz[x]=1;
	fa[x]=f;
	for(int i=0;i<(int)to[x].size();i++)
	{
		int y=to[x][i];
		if(y==f)
			continue;
		dfs1(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]])
			son[x]=y;
	}
}
void dfs2(int x,int t)
{
	top[x]=t;
	if(son[x])
		dfs2(son[x],t);
	for(int i=0;i<(int)to[x].size();i++)
	{
		int y=to[x][i];
		if(y==fa[x]||y==son[x])
			continue;
		dfs2(y,y);
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		x=fa[top[x]];
	}
	return (dep[x]<dep[y])?x:y;
}
void dfss(int x)
{
	viss[x]=1;
	for(int i=0;i<(int)to[x].size();i++)
	{
		int y=to[x][i];
		if(viss[y]||!vis[y])
			continue;
		dfss(y);
	}
}
int sol(bool vis[])
{
	int tot=0;
	for(int i=1;i<=n;i++)
		viss[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]&&!viss[i])
		{
			if(tot==2)
				return -1;
			dfss(i),tot++;
		}	
	}
	int res=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			int minn=INT_MAX;
			for(int j=1;j<=n;j++)
				if(vis[j])
					minn=min(minn,dep[i]+dep[j]-2*dep[lca(i,j)]);
			res=max(res,minn);
		}
	return res;
}
void dfs(int x,int cnt,bool vis[])
{
	if(cnt+(n-x+1)<k)
		return;
	if(x==n+1)
	{
		if(cnt==k)
		{
			int val=sol(vis);
			if(val!=-1)
				ans=min(ans,val);
		}
		return;
	}
	vis[x]=1;
	dfs(x+1,cnt+1,vis);
	vis[x]=0;
	dfs(x+1,cnt,vis);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ans=INT_MAX;
		cin>>n>>k;
		memset(dep,0,sizeof dep);
		memset(siz,0,sizeof siz);
		memset(fa,0,sizeof fa);
		memset(son,0,sizeof son);
		memset(top,0,sizeof top);
		memset(vis,0,sizeof vis);
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		dfs1(1,0);
		dfs2(1,1);
		dfs(1,0,vis);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)
			to[i].clear();
	}
	return 0;	
}
