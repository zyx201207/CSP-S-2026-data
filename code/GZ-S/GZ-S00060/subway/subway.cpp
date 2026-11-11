//GZ-S00060 贵阳市第一中学 王羿翔
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll c, n, m, d, q; cin >> c >> n >> m >> d >> q;
	vector<ll> a(m + 1);
	for (ll i = 1; i <= m; i++) cin >> a[i];
	vector<vector<ll> > dist(n + m + 1, vector<ll>(n + m + 1, INF));
	for (ll i = 1; i <= n; i++) {
		ll k; cin >> k;
		for (ll j = 1; j <= k; j++) {
			ll u, t; cin >> u >> t;
			dist[u][m + i] = dist[m + i][u] = t;
		}
	}
	for (ll i = 1; i <= n + m; i++) dist[i][i] = 0;
	for (ll i = 1; i <= n + m; i++) for (ll j = 1; j <= n + m; j++)
		for (ll k = 1; k <= n + m; k++)
			dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][k] + dist[k][j]);
	while (q--) {
		ll x, y; cin >> x >> y;
		cout << dist[x][y] + a[x] + a[y] << '\n'; 
	}
	return 0;
}
