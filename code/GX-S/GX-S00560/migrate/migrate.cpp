#include<iostream>
#include<algorithm>
#include<queue>
auto III = freopen("migrate.in", "r", stdin);
auto OOO = freopen("migrate.out", "w", stdout);
auto SSS = std::cin.tie(0) -> sync_with_stdio(0);
#ifdef BUG
#define bug(x...) ({x;void();})
#else
#define bug(x...) ({})
#endif
#define LL long long
#define pb push_back
#define vec vector
#define SIZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define RNG(x,l,r) &(x)[l], 1 + &(x)[r]
#define rep(i,l,r) for(int i = (l), i##_ = (r); i <= i##_; i++)
void tomax(auto&x, auto&&y){ if(y > x) x = y; }
void tomin(auto&x, auto&&y){ if(y < x) x = y; }
using namespace std; namespace __{

#define int LL
constexpr int N = 2e6 + 5, INF64 = 1LL << 61, P = 1e9 + 7;
int n,d;
int a[N];
vec<int> G[N];
int dis[N],f[N],vis[N];

void clear(){
	rep(i,0,n) G[i].clear();
}

void dij(int s){
	fill(RNG(dis,0,n), INF64);
	fill(RNG(f,0,n), 0);
	fill(RNG(vis,0,n), 0);
	deque<int> q;
	q.pb(s);
	dis[s] = 0, f[s] = 1;
	while(SIZ(q)){
		int u = q.front();
		q.pop_front();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto v:G[u]){
			if(dis[v] > dis[u] + 1){
				f[v] = f[u];
				dis[v] = dis[u] + 1;
				q.pb(v);
			}else if(dis[v] == dis[u] + 1){
				f[v] = (f[v] + f[u]) % P;
			}
		}
	}
}

void main(){
	signed tid,cse; for(cin>>tid>>cse; cse--; clear())
[&](){
	cin>>n>>d;
	rep(i,1,n) cin>>a[i];

	rep(i,1,n){
		rep(j,i+1,n){
			if(a[j] - a[i] <= d){
				G[i].pb(j);
			}
		}
	}

	int ans=0;
	rep(i,1,n){
		dij(i);
		rep(j,i+1,n){
			if(f[j] == 2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}();}}
signed main(){ __::main(); }
