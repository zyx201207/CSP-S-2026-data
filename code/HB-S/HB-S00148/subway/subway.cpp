#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll N = 5e2 + 5, K = 5e5 + 5;
ll c, n, m, d, q, w[N], p[N][K], t[N][K], dis[N][K], mapn[K][K], s[N][N], e[N][N];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++) {
		for (ll j = 1; j <= m; j++) {
			if (i == j) continue;
			mapn[i][j] = 1e9;
		}
	}
	for (ll i = 1; i <= m; i++) cin >> w[i];
	for (ll i = 1, tmp; i <= n; i++) {
		cin >> tmp;
		for (ll j = 1; j <= tmp; j++) cin >> p[i][j] >> t[i][j], dis[p[i][j]][i] = t[i][j];
		for (ll a = 1; a <= tmp; a++) {
			for (ll b = 1; b <= tmp; b++) {
				mapn[p[i][a]][p[i][b]] = dis[p[a][i]][i] + dis[p[b][i]][i];
				mapn[p[i][b]][p[i][a]] = dis[p[a][i]][i] + dis[p[b][i]][i];
			}
		}
	}
	for (ll k = 1; k <= n; k++) {
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				if (mapn[i][j] > mapn[i][k] + mapn[k][j]) {
					mapn[i][j] = mapn[i][k] + mapn[k][j];
				}
			}
		}
	}
	while (q--) {
		ll sx, ey;
		cin >> sx >> ey;
		cout << w[sx] + w[ey] + mapn[sx][ey] << endl;
	}	
	return 0;
}
