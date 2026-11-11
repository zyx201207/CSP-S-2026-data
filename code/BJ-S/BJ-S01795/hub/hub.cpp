#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int c,t,n,k,u[N],v[N];
vector<int>edge[N];
int cnt,fa[N],ans;
bool book[N];
int find(int x)
{
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int f[N];
void dfs1(int u,int fa)
{
	if(book[u])f[u]=0;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v==fa)continue;
		dfs1(v,u);
		f[u]=min(f[u],f[v]+1);
	}
	return;
}
void dfs2(int u,int fa)
{
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v==fa)continue;
		f[v]=min(f[v],f[u]+1);
		dfs2(v,u);
	}
	return;
}
void dfs(int p)
{
	if(p>n)
	{
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<n;i++)
		{
			if(!book[u[i]]||!book[v[i]])continue;
			if(find(u[i])!=find(v[i]))
				fa[find(u[i])]=find(v[i]);
		}
		int tt=0;
		for(int i=1;i<=n;i++)if(book[i]&&fa[i]==i)tt++;
		if(tt>2)return;
		for(int i=1;i<=n;i++)f[i]=n+1;
		dfs1(1,1);
		dfs2(1,1);
		int mx=0;
		for(int i=1;i<=n;i++)mx=max(mx,f[i]);
		// for(int i=1;i<=n;i++)cout<<book[i];cout<<endl;
		// for(int i=1;i<=n;i++)cout<<f[i]<<' ';cout<<endl;
		ans=min(ans,mx);
		return;
	}
	if(cnt+n-p>=k)dfs(p+1);
	if(cnt<k)
	{
		book[p]=true;
		cnt++;
		dfs(p+1);
		book[p]=false;
		cnt--;
	}
	return;
}
void solve()
{
	cin>>n>>k;
	cnt=0;
	for(int i=1;i<=n;i++)edge[i].clear();
	int x,y;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		u[i]=x,v[i]=y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	ans=2147483647;
	dfs(1);
	cout<<ans<<'\n';
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}