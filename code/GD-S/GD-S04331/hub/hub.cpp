/*
Oct31==Dec25?
freopen neuvillette.in/out r/w stdin/out
crystal subway migrate hub
14:30~18:30
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
constexpr int N=1e6+7;
constexpr int K=21;
vector<int> g[N];     //多测要清空！！！ 
int fa[N][K],dep[N]; 
int n,k;
void dfslca(int u,int p)
{
	fa[u][0]=p;
	dep[u]=dep[p]+1;
	for(int i=1;i<K;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:g[u]) if(v!=p) dfslca(v,u);
}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=K-1;i>=0;i--) if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	if(u==v) return u;
	for(int i=K-1;i>=0;i--) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
inline ll dis(int u,int v)
{
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
class DSU
{
public:
	int p[N];
	void init()
	{
		for(int i=1;i<=n;i++) p[i]=i;
	}
	int find(int u)
	{
		return p[u]==u?u:p[u]=find(p[u]);
	}
	void merge(int u,int v)
	{
		p[find(u)]=find(v);
	}
}dsu;
int hub[N];
bool is[N];
ll ans=1e18;
inline bool check()
{
	dsu.init();
	for(int i=1;i<=k;i++)
	{
		int u=hub[i];
		for(int v:g[u])
			if(is[v])
			{
				dsu.merge(u,v);
//				cerr<<'M'<<u<<' '<<v<<'\n';
			}
	}
	int cnt=0;
	for(int i=1;i<=k;i++) if(dsu.p[hub[i]]==hub[i]) cnt++;
	return cnt<=2;
}
inline ll calc()
{
	ll mx=0;
	for(int i=1;i<=n;i++)
	{
		ll mn=1e18;
		for(int j=1;j<=k;j++)
		{
			mn=min(mn,dis(i,hub[j]));
		}
		mx=max(mx,mn);
	}
	return mx;
}
void dfs(int dep)
{
	if(dep>k)
	{
//		cerr<<check()<<' '<<calc()<<':';
//		for(int i=1;i<=k;i++) cerr<<hub[i]<<" \n"[i==k];
		if(check()) ans=min(ans,calc());
		return;
	}
	for(int i=hub[dep-1]+1;i<=n;i++)
	{
		hub[dep]=i;
		is[i]=1;
		dfs(dep+1);
		is[i]=0;
	}
}
inline ll solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		g[i].clear();
		dep[i]=0;
		for(int j=0;j<K;j++) fa[i][j]=0;
	}
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfslca(1,0);
	ans=1e18;
	dfs(1);
	return ans;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int cid,T;
	cin>>cid>>T;
	while(T--) cout<<solve()<<'\n';
	cout.flush();
	return 0;
}
/*
暴力：
连通块数量用并查集，枚举城市用dfs
计算距离用LCA 

16:45写完暴力 
*/
