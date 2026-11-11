#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
template<class T>bool ckmax(T &x,const T y){return x<y?x=y,1:0;}
template<class T>bool ckmin(T &x,const T y){return x>y?x=y,1:0;}
inline int read(){
	int f=1,w=0,ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) w=(w<<3)+(w<<1)+(ch^48);
	return f*w;
}
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) ((x).begin(),(x).end())
#define sz(x) (int)(x.size()) 
const int N = 510, M = 5e5 + 10, INF = 1e18;
int c, n, m, d, q;
int a[M];
vector<pii> b[M];
int dis[N][N];
signed main() {
//	freopen("subway7.in", "r", stdin);
//	freopen("subway7.out", "w", stdout);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	rep(i, 1, m) a[i] = read();
	rep(i, 1, n) {
		int cnt = read();
		rep(j, 1, cnt) {
			int id = read(), ti = read();
			b[id].pb({ti, i});
		}
	}
	rep(i, 1, n) rep(j, 1, n) {
		if (i == j) continue;
		dis[i][j] = INF;
	}
	rep(i, 1, m) {
		rep(j, 0, sz(b[i]) - 1) {
			rep(k, j + 1, sz(b[i]) - 1) {
				pii x = b[i][j], y = b[i][k];
				if (x.se > y.se) swap(x, y);
				ckmin(dis[x.se][y.se], x.fi + y.fi);
			}
		}
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			rep(k, j + 1, n) {
				ckmin(dis[j][k], dis[j][i] + dis[i][k]);
			}
		}
	}
	while (q--) {
		int S = read(), T = read();
		int ans = INF;
		rep(i, 0, sz(b[S]) - 1) {
			rep(j, 0, sz(b[T]) - 1) {
				pii x = b[S][i], y = b[T][j];
				if (x.se > y.se) swap(x, y);
				ckmin(ans, x.fi + y.fi + dis[x.se][y.se]);
			}
		}
		printf("%lld\n", ans + a[S] + a[T]);
	}
	return 0;
}

