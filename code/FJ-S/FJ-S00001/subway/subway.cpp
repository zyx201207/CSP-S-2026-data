#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, inf = 1e18;
int c, n, m, d, q, w[N], dis[505][505], k, a, t, x, y;
vector< pair<int, int> > s[N]; 
signed main() {
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			s[a].push_back({t, i});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if(i != j) dis[i][j] = inf;
	for (int i = 1; i <= m; i++) {
		int l = (int)s[i].size();
		for (int x = 0; x < l; x++) {
			for (int y = x + 1; y < l; y++) {
				int idx = s[i][x].second, idy = s[i][y].second;
				dis[idx][idy] = dis[idy][idx] = min(dis[idx][idy], s[i][x].first + s[i][y].first);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if(dis[i][k] == inf) continue;
			for (int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}
	while(q --) {
		cin >> x >> y;
		int ans = inf;
		for (pair<int, int> xx : s[x]) {
			for (pair<int, int> yy : s[y]) ans = min(ans, dis[xx.second][yy.second] + xx.first + yy.first);
		} cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
