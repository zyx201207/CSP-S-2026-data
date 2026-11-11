#include <bits/stdc++.h>
using namespace std;
//#define int long long
using ll = long long;
#define rep(i, a, b) for (int i = a; i <= b; i ++ )
#define per(i, a, b) for (int i = a; i >= b; i -- )
#define pii pair<int, ll>
#define id first
#define ww second
#define pb push_back
inline ll mymax(ll a, ll b) { return (a > b) ? a : b; }
inline ll mymin(ll a, ll b) { return (a < b) ? a : b; }
inline void _max(ll &a, ll b) { a = mymax(a, b); }
inline void _min(ll &a, ll b) { a = mymin(a, b); }

// subway

int C, n, m, d, q;
const int N = 505, M = 5e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll w[M]; int k[N], a[N][N]; ll t[N][N];
ll dis[N][N];
vector <pii> sta[M];

//template <class T>
//inline void read(T &a) {
//	a = 0; int ch = getchar(); 
//	for (; !isdigit(ch); ch = getchar());
//	for (; isdigit(ch); ch = getchar()) a = (a << 3) + (a << 1) + (ch ^ 48);
//}

void solve() {
	cin >> C >> n >> m >> d >> q;
//	read(C), read(n), read(m), read(d), read(q);
	rep(i, 1, n) rep(j, 1, n) dis[i][j] = INF;
	rep(i, 1, n) dis[i][i] = 0;
	rep(i, 1, m) cin >> w[i];
//	rep(i, 1, m) read(w[i]);
	rep(i, 1, n) {
		cin >> k[i];
//		read(k[i]);
		rep(j, 1, k[i]) {
			cin >> a[i][j] >> t[i][j];
//			read(a[i][j]), read(t[i][j]);
			sta[a[i][j]].pb({i, t[i][j]});
		}
	}
	int u, v; ll wu, wv;
	for (int i = 1; i <= m; i ++ ) {
		int num = sta[i].size();
		if (num == 0) continue;
		rep(j, 0, num - 1) {
			u = sta[i][j].id, wu = sta[i][j].ww;
			rep(k, j + 1, num - 1) {
				if (j == k) continue;
				v = sta[i][k].id, wv = sta[i][k].ww;
				_min(dis[u][v], wu + wv);
				_min(dis[v][u], wu + wv);
			}
		}
	}
	rep(k, 1, n) {
		rep(i, 1, n) 
			rep(j, 1, n)
				_min(dis[i][j], dis[i][k] + dis[k][j]);
	}
	for (int r = 1, x, y; r <= q; r ++ ) {
		cin >> x >> y;
//		read(x), read(y);
		ll res = INF;
		int n1 = sta[x].size(), n2 = sta[y].size();
		rep(i, 0, n1 - 1) {
			u = sta[x][i].id, wu = sta[x][i].ww;
			rep(j, 0, n2 - 1) {
				v = sta[y][j].id, wv = sta[y][j].ww;
				_min(res, dis[u][v] + wu + wv);
			}
		}
		res += w[x] + w[y];
		cout << res << '\n';
	}
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T -- ) solve();
	return 0;
}
// 16:19
