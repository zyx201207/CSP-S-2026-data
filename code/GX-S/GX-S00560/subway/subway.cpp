#include<iostream>
#include<algorithm>
#include<queue>
auto III = freopen("subway.in", "r", stdin);
auto OOO = freopen("subway.out", "w", stdout);
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
#define RNG(x,l,r) &(x)[l], 1 + &(x)[r]
#define rep(i,l,r) for(int i = (l), i##_ = (r); i <= i##_; i++)
void tomax(auto&x, auto&&y){ if(y > x) x = y; }
void tomin(auto&x, auto&&y){ if(y < x) x = y; }
using namespace std; namespace __{

constexpr LL N = 500 + 5, MM = 5e5 + 5, INF64 = 1ll << 61;
int c,n,m,d,q;
int w[MM];
vec<pair<int,int>> l[MM];
LL dis[N][N];

void main(){
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m) cin>>w[i];
	rep(i,1,n){
		int k; cin>>k;
		rep(j,1,k){
			int x,t; cin>>x>>t;
			l[x].pb({i,t});
		}
	}
	
	rep(i,1,n) rep(j,1,n) if(i != j) dis[i][j] = INF64;

	rep(x,1,m){
		bug(cout<<"----------------"<<x<<endl);
		int ccc = SIZ(l[x]);
		rep(i,0,ccc-1){
			rep(j,i+1,ccc-1){
				auto [p,t1] = l[x][i];
				auto [q,t2] = l[x][j];
				bug(cout<<p<<' '<<q<<": "<<t1+t2<<endl);
				tomin(dis[p][q], t1 + t2);
			}
		}
	}

	rep(i,1,n) rep(j,1,n) dis[i][j] = dis[j][i] = min(dis[i][j], dis[j][i]);

	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				tomin(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	rep(_,1,q){
		int x,y; cin>>x>>y;
		int c1 = SIZ(l[x]), c2 = SIZ(l[y]);
		LL ans = INF64;
		rep(i,0,c1-1){
			rep(j,0,c2-1){
				auto [p,t1] = l[x][i];
				auto [q,t2] = l[y][j];
				tomin(ans, t1 + dis[p][q] + t2);
			}
		}
		bug(cout << "ans "<<ans << endl);
		cout << w[x] + ans + w[y] << '\n';
	}
}}
signed main(){ __::main(); }
