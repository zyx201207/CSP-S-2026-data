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
	// clock_t BG=clock();
	file(subway);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>CID;
	Solve();
	// fprintf(stderr,"TIME=%.2lfs\n",1.*(clock()-BG)/CLOCKS_PER_SEC);
}
const ll INF = 0x3f3f3f3f3f3f3f3f;
void Solve() {
	int n,m,D,Q; cin>>n>>m>>D>>Q;
	vec<int> at(m);
	for(int i=0;i<m;i++) cin>>at[i];
	vv<pair<int,int>> g(m);
	for(int i=0;i<n;i++) {
		int k; cin>>k;
		for(int j=0;j<k;j++) {
			int x,w; cin>>x>>w;
			g[--x].push_back({i,w});
		}
	}
	vv<ll> e(n,vec<ll>(n,INF));
	for(int i=0;i<n;i++) e[i][i]=0;
	for(int i=0;i<m;i++)
		for(auto [u,a]:g[i]) for(auto [v,b]:g[i])
			Min<ll>(e[u][v],a+b);
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				Min(e[i][j],e[i][k]+e[k][j]);
	while(Q--) {
		int x,y; cin>>x>>y; --x,--y;
		ll res=INF;
		for(auto [u,a]:g[x]) for(auto [v,b]:g[y])
			Min(res,a+e[u][v]+b);
		res+=at[x]+at[y];
		cout<<res<<'\n';
	}
}