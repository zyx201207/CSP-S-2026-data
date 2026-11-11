/**
 * @file CSP-S 2026
 *       Problem B. subway
 * @author BJ-S01809
 *         LG-1014842 liuli688
 * @date 2026/10/31
*/
//password: Oct31==Dec25?

// Let you forgive me
// Destr0yer - Sakuzyo

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fst first
#define snd second
const int N = 5e5 + 10;
int c, n, m, d, q;
ll ww[N], dis[510][510];
vector<pll> G[N];

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// double St = clock();
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		cin >> ww[i];
	for (int i = 1, k, a, t; i <= n; ++i) {
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			cin >> a >> t;
			G[a].emplace_back(i, t);
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; ++i)
		dis[i][i] = 0;
	for (int i = 1; i <= m; ++i)
		for (auto u : G[i])
			for (auto v : G[i]) {
				dis[u.fst][v.fst] = min(dis[u.fst][v.fst], u.snd + v.snd);
				dis[v.fst][u.fst] = min(dis[v.fst][u.fst], u.snd + v.snd);
			}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int x, y; q--; ) {
		cin >> x >> y;
		ll ans = 1e18;
		for (auto i : G[x])
			for (auto j : G[y])
				ans = min(ans, dis[i.fst][j.fst] + i.snd + j.snd);
		cout << ans + ww[x] + ww[y] << '\n';
	}
	// cerr << (clock() - St) / CLOCKS_PER_SEC << '\n';
	return 0;
}

// 旅途未完 千山万水空白待绘

//15:36