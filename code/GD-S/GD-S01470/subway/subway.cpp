#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
struct edges{
	int u,v;
	ll w;
	bool operator<(const edges& i)const{
		return w<i.w;
	}
};
struct edge{
	int to;
	ll dis;
	int nxt;
};

const ll INF=1e18;
const int N=510,M=5e5+10;
int n,m;
ll a[M];

vector<pil> way[M];
int idx;
edges es[M];
int cnt;

int dsu[N];
void init(int sz){
	for(int i=1;i<=sz;i++) dsu[i]=i;
}
int fnd(int x){
	return dsu[x]==x ? x : dsu[x]=fnd(dsu[x]);
}

edge e[N<<1];
int head[N],tot;
int fa[N],son[N],dep[N],siz[N],top[N];
ll pre[N];
int lca[N][N];
void add(int u,int v,ll w){
	e[++tot]=edge{v,w,head[u]},head[u]=tot;
}
void dfs1(int x){
	dep[x]=dep[fa[x]]+1,siz[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		int t=e[i].to;
		if(t==fa[x]) continue;
		fa[t]=x,pre[t]=pre[x]+e[i].dis;
		dfs1(t);
		siz[x]+=siz[t];
		if(!son[x]||siz[t]>siz[son[x]]) son[x]=t;
	}
}
void dfs2(int x,int tp){
	top[x]=tp;
	if(son[x]) dfs2(son[x],tp);
	for(int i=head[x];i;i=e[i].nxt){
		int t=e[i].to;
		if(t==fa[x]||t==son[x]) continue;
		dfs2(t,t);
	}
}
int LCA(int u,int v){
	while(top[u]!=top[v]) dep[top[u]]>=dep[top[v]] ? u=fa[top[u]] : v=fa[top[v]];
	return dep[u]<dep[v] ? u : v;
}

ll ans;

void Solve()
{
	int d,q;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int u=1;u<=n;u++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int v;
			ll w;
			cin>>v>>w;
			way[v].emplace_back(pil{u,w});
		}
	}
	idx=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<(int)way[i].size();j++)
			for(int k=j+1;k<(int)way[i].size();k++){
				es[++idx]=edges{way[i][j].first,way[i][k].first,way[i][j].second+way[i][k].second};
			}	
	sort(es+1,es+idx+1);
	init(n);
	cnt=0;
	tot=0;
	for(int i=1;i<=idx;i++){
		int u=fnd(es[i].u),v=fnd(es[i].v);
		if(u==v) continue;
		dsu[v]=u;
		add(es[i].u,es[i].v,es[i].w),add(es[i].v,es[i].u,es[i].w);
		if(++cnt==n-1) break;
	}
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++) lca[i][j]=LCA(i,j);
//	for(int i=1;i<=n;i++) cout<<way[i].size()<<" ";cout<<"\n";
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=INF;
		for(int i=0;i<(int)way[x].size();i++)
			for(int j=0;j<(int)way[y].size();j++){
				int u=way[x][i].first,v=way[y][j].first;
				if(u>v) swap(u,v);
				ans=min(ans,a[x]+a[y]+way[x][i].second+way[y][j].second+(pre[u]+pre[v]-pre[lca[u][v]]*2));
			}
		cout<<ans<<"\n";
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1,c;
//	cin>>T;
	cin>>c;
	while(T--){
		Solve();
	}
	return 0;
}
