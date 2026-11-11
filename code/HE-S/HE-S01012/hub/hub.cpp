#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#define intt long long
#define intu unsigned long long
#define dle double
#define dlel long double
const int N=35;
int c,t;
int n,k;
struct Edge{int v,next;}g[N<<1];
int head[N];
int cnt;
void add(int u,int v)
{
	g[++cnt]=(Edge){v,head[u]};
	head[u]=cnt;
	g[++cnt]=(Edge){u,head[v]};
	head[v]=cnt;
}
int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y){fa[find(x)]=find(y);}
std::vector<int> v;
std::set<int> st;
int fff[N];
int check()
{
	memset(fff,0,sizeof(fff));
	for(int i:v) fff[i]=1;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int u:v)
	{
		for(int i=head[u];i;i=g[i].next)
		{
			int v=g[i].v;
			if(!fff[v]) continue;
			if(find(u)==find(v)) continue;
			merge(u,v);
		}
	}
	st.clear();
	for(int i:v) st.insert(find(i));
	return st.size()==2;
}
int f[N],dep[N];
void DFS(int u)
{
	dep[u]=dep[f[u]]+1;
	for(int i=head[u];i;i=g[i].next)
	{
		int v=g[i].v;
		if(v==f[u]) continue;f[v]=u;
		DFS(v);
	}
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y]) std::swap(x,y);
	while(dep[x]>dep[y]) x=f[x];
	if(x==y) return x;
	while(x!=y) x=f[x],y=f[y];
	return x;
}
int dist(int x,int y){return dep[x]+dep[y]-2*dep[LCA(x,y)];}
int ans;
void dfs(int z,int pre)
{
	if(!z)
	{
		if(!check()) return;
		int maxn=0;
		for(int x=1;x<=n;x++)
		{
			int mink=n;
			for(int y:v) mink=std::min(mink,dist(x,y));
			maxn=std::max(maxn,mink);
		}
		ans=std::min(ans,maxn);
		return;
	}
	for(int i=pre+1;i<=n;i++)
	{
		v.push_back(i);
		dfs(z-1,i);
		v.pop_back();
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		cnt=0;for(int i=1;i<=n;i++) head[i]=0;
		scanf("%d%d",&n,&k);
		for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),add(u,v);
		ans=n;DFS(1);dfs(k,0);
		printf("%d\n",ans);
	}
	return 0;
}
