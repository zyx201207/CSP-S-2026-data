#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 510, M = 500010;
ll w[M];
vector<pair<ll, ll>> g[M];
ll dist[N][N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (ll i = 1; i <= n; i++) {
		ll k;
		cin >> k;
		while (k--) {
			ll a, t;
			cin >> a >> t;
			g[a].push_back({i, t});
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			if (i != j) {
				dist[i][j] = LLONG_MAX / 2;
			}
		}
	}
	for (ll i = 1; i <= m; i++) {
		for (ll j = 0; j + 1 < g[i].size(); j++) {
			for (ll k = j + 1; k < g[i].size(); k++) {
				dist[g[i][j].first][g[i][k].first] = dist[g[i][k].first][g[i][j].first] =
					min(dist[g[i][j].first][g[i][k].first], g[i][j].second + g[i][k].second);
			}
		}
	}
	for (ll k = 1; k <= n; k++) {
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	while (q--) {
		ll x, y;
		cin >> x >> y;
		ll ans = LLONG_MAX;
		for (ll i = 0; i < g[x].size(); i++) {
			for (ll j = 0; j < g[y].size(); j++) {
				ans = min(ans, dist[g[x][i].first][g[y][j].first] +
				               g[x][i].second + g[y][j].second);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
