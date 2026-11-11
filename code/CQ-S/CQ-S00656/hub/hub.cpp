#include<bits/stdc++.h>
#define file(F) (void)freopen(#F".in","r",stdin),(void)freopen(#F".out","w",stdout)
#define ALL(x) begin((x)),end((x))
#define lowbit(x) ((x)&-(x))
#define ppc(x) (__builtin_popcountll(x))
using namespace std;
template<typename T> bool Max(T &x,T y) { return x<y&&(x=y,true); }
template<typename T> bool Min(T &x,T y) { return x>y&&(x=y,true); }
template<typename T> T abs(const T &x) { return x>0?x:-x; }
template<typename T> using vec=vector<T>;
template<typename T> using vv=vec<vec<T>>;
template<typename T> using vvv=vec<vv<T>>;
template<typename T> using vvvv=vv<vv<T>>;
using ull=unsigned long long;
using ll=long long;
void Solve();
int CID;
signed main() {
	file(hub);
	cin.tie(nullptr)->sync_with_stdio(false);
	int T; cin>>CID>>T; while(T--)
	Solve();
}
const int INF = 0x3f3f3f3f;
void Solve() {
	int n,m; cin>>n>>m;
	vec<pair<int,int>> G;
	vv<int> e(n);
	for(int i=1;i<n;i++) {
		int u,v; cin>>u>>v; --u,--v;
		e[u].push_back(v),e[v].push_back(u);
		G.push_back({u,v});
	}
	vec<int> dep(n),md(n);
	vec<int> sz(n);
	vv<int> f(n);
	function<void(int,int)> dfs = [&](int u,int fa) {
		sz[u]=1; md[u]=dep[u];
		f[u]={INF,0};
		for(auto v:e[u]) if(v!=fa) {
			dep[v]=dep[u]+1,dfs(v,u);
			Max(md[u],md[v]);
			vec<int> g(min(sz[u]+sz[v],m)+1,INF);
			for(int i=1;i<=min(sz[u],m);i++) {
				Min(g[i],max(f[u][i],md[v]-dep[u]));
				for(int j=1;j<=min(sz[v],m-i);j++)
					Min(g[i+j],max(f[u][i],f[v][j]));
			}
			f[u]=move(g); sz[u]+=sz[v];
		}
	};
	vec<int> _(m+1,INF);
	function<void(int,int,int)> dfs1 = [&](int u,int fa,int ld) {
		for(int i=1;i<=min(sz[u],m);i++)
			Min(_[i],max(f[u][i],ld+dep[u]));
		array<array<int,2>,2> o{-INF,-1,-INF,-1};
		o[0]={0,u};
		for(auto v:e[u]) if(v!=fa) {
			array<int,2> ov{md[v]-2*dep[u],v};
			if(ov>o[0]) swap(ov,o[0]);
			if(ov>o[1]) swap(ov,o[1]);
		}
		for(auto v:e[u]) if(v!=fa) {
			if(o[0][1]==v) dfs1(v,u,max(ld,o[1][0]));
			else dfs1(v,u,max(ld,o[0][0]));
		}
	};
	dfs(0,-1),dfs1(0,-1,-INF);
	int ans=_[m]; fill(ALL(_),INF);
	for(auto [x,y]:G) {
		dep[x]=dep[y]=0,dfs(x,y),dfs(y,x);
		vec<int> p(min(sz[x],m)+1,INF);
		vec<int> q(min(sz[y],m)+1,INF);
		dfs1(x,y,0);
		for(int i=1;i<=min(sz[x],m);i++) swap(p[i],_[i]);
		dfs1(y,x,0);
		for(int i=1;i<=min(sz[y],m);i++) swap(q[i],_[i]);
		for(int i=1;i<=min(sz[x],m);i++)
			if(m-i<=sz[y]) Min(ans,max(p[i],q[m-i]));
	}
	cout<<ans<<'\n';
}