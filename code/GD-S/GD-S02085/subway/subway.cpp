#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int MAXN = 505, MAXM = 5e5 + 5;
const ll inf = 1e18;

template<typename T> void chkMin(T &x, T y) { x = y < x ? y : x; }
template<typename T> void chkMax(T &x, T y) { x = y > x ? y : x; }

int tid, n, m, d, q, w[MAXM];
vector<pii> r[MAXM];
ll dis[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> tid >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		while (k--) {
			int a, t;
			cin >> a >> t;
			r[a].emplace_back(i, t);
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dis[i][j] = i == j ? 0 : inf;
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		int sz = r[i].size();
		for (int x = 0; x < sz; ++x) {
			for (int y = x + 1; y < sz; ++y) {
				auto [px, tx] = r[i][x];
				auto [py, ty] = r[i][y];
				chkMin<ll>(dis[px][py], tx + ty);
				chkMin<ll>(dis[py][px], tx + ty);
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				chkMin(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		
		ll ans = inf;
		for (auto [px, tx] : r[x]) {
			for (auto [py, ty] : r[y]) {
				chkMin(ans, w[x] + w[y] + dis[px][py] + tx + ty);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
