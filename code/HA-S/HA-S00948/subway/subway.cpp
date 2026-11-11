#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 505;
const int M = 5e5 + 10;
typedef long long ll;
const ll inf = 1e16;
int _c, n, m, _d, Q;
ll _w[M], dis[N][N];
vector<pair<int, int>> vec[N], to[M];
inline void cmin(ll &u, ll v) {
	u = min(u, v);
	return;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> _c >> n >> m >> _d >> Q;
	for (int i = 1; i <= m; i++) cin >> _w[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k; int a, t;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			vec[i].push_back(mp(a, t));
			to[a].push_back(mp(i, t));
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) dis[i][j] = inf;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (auto p : vec[i]) {
			for (auto q : to[p.fi]) {
				if (q.fi == i) continue;
				cmin(dis[i][q.fi], p.se + q.se);
				cmin(dis[q.fi][i], p.se + q.se);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cmin(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	int x, y; ll ans, bas;
	while (Q--) {
		cin >> x >> y;
		bas = _w[x] + _w[y], ans = inf;
		for (auto p : to[x]) {
			for (auto q : to[y]) {
				cmin(ans, bas + p.se + q.se + dis[p.fi][q.fi]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
// 15.35