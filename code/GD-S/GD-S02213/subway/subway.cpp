#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using i128 = __int128;

using PII = pair<int, int>;
using PLL = pair<ll, ll>;

#define fi first
#define se second

#define rep(i, j, k) for (int (i) = (j); (i) < (k); (i)++)
#define __rep(i, j, k) for (int (i) = (j); (i) <= (k); (i)++)

constexpr ll inf = (1ll << 62);
constexpr int N = 5e5 + 10, M = 505;

template <typename T> void chkmax(T& a, T b) { a = max(a, b); }
template <typename T> void chkmin(T& a, T b) { a = min(a, b); }

int n, m, d, q, w[N];
ll dis[M][M];
vector<vector<PII>> id(N);

void solve() {
	cin >> n >> m >> d >> q;
	__rep(i, 1, m) {
		cin >> w[i];
	}
	__rep(i, 1, n) {
		int k;
		cin >> k;
		rep(j, 0, k) {
			int a, t;
			cin >> a >> t;
			id[a].push_back({i, t});
		}
	}
	__rep(i, 1, n) __rep(j, 1, n) {
		dis[i][j] = inf;
	}
	__rep(i, 1, n) {
		dis[i][i] = 0;
	}
	
	__rep(i, 1, m) {
		rep(j, 0, id[i].size()) rep(p, j + 1, id[i].size()) {
			int x = id[i][j].fi, y = id[i][p].fi;
			ll wx = id[i][j].se, wy = id[i][p].se;
//			cout << i << " " << x << " " << y << " " << wx << " " << wy << "\n"; 
			chkmin(dis[x][y], wx + wy);
			chkmin(dis[y][x], wx + wy);
		}
	}
	
	__rep(p, 1, n) __rep(i, 1, n) __rep(j, 1, n) {
		if (dis[i][p] == inf || dis[p][j] == inf) continue;
		chkmin(dis[i][j], dis[i][p] + dis[p][j]);
	}
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll ans = w[x] + w[y], cur = inf;
		
		rep(i, 0, id[x].size()) rep(j, 0, id[y].size()) {
			int u = id[x][i].fi, v = id[y][j].fi;
			ll wu = id[x][i].se, wv = id[y][j].se;
			chkmin(cur, dis[u][v] + wu + wv);
//			cerr << x << " " << y << " " << u << " " << v << "\n";
		}
		
		cout << ans + cur << "\n";
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int c;
	cin >> c;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
