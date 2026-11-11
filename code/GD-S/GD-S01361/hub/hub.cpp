#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,inf=1e9;
int a[N],fa[N];
int findfa(int x){return fa[x]==x?fa[x]:fa[x]=findfa(fa[x]);}
void merge(int x,int y)
{
	int tx=findfa(x),ty=findfa(y);
	if(tx!=ty)fa[tx]=ty;
}
vector<int>G[N];
struct node{int x,y;}e[N];
int dep[N],st[N][20];
void dfs(int x,int f)
{
	dep[x]=dep[f]+1;
	st[x][0]=f;for(int i=1;i<=10;i++)st[x][i]=st[st[x][i-1]][i-1];
	for(int y:G[x])if(y!=f)
		dfs(y,x);
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--)if(dep[st[x][i]]>=dep[y])x=st[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)if(st[x][i]!=st[y][i])x=st[x][i],y=st[y][i];
	return st[x][0];
}
int dis(int x,int y)
{
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void solve()
{
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)G[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
		e[i]={x,y};
	}
	dfs(1,0);
	int ans=inf;
	for(int i=1;i<(1<<n);i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)if(i&(1<<(j-1)))cnt++;
		if(cnt!=k)continue;
		for(int j=1;j<=n;j++)fa[j]=j;
		for(int j=1;j<n;j++)if(i&(1<<(e[j].x-1))&&i&(1<<(e[j].y-1)))
			merge(e[j].x,e[j].y);
		cnt=0;
		for(int j=1;j<=n;j++)if(i&(1<<(j-1))&&fa[j]==j)cnt++;
		if(cnt>2)continue;
		int mx=0;
		for(int p=1;p<=n;p++)
		{
			int mn=inf;
			for(int j=1;j<=n;j++)if(i&(1<<(j-1)))
			{
				mn=min(mn,dis(p,j));
			}
			mx=max(mx,mn);
		}
		ans=min(ans,mx);
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)solve();
	return 0;
}
