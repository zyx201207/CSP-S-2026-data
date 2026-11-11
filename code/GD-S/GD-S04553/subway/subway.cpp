#define ffopen(s) \
cin.tie(0)->sync_with_stdio(0); \
freopen(#s ".in", "r", stdin); \
freopen(#s ".out", "w", stdout); \
//
#include <bits/stdc++.h>
using namespace std;
using intl = long long;
const intl inf = 0x3f3f3f3f3f3f3f3f, N = 500, M = 500000;
int c, n, m, d, q, K[N + 10];
intl w[M + 10], dis[N + 10][N + 10];
vector<pair<int, intl> > sts[M + 10];
int main() { ffopen(subway);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> K[i];
		for (int j = 1; j <= K[i]; j++) {
			int a; intl t;
			cin >> a >> t;
			sts[a].emplace_back(i, t);
		}
	}
	
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	
	// m * d * d ?
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < sts[i].size(); j++) {
			int a = sts[i][j].first;
			intl ta = sts[i][j].second;
			for (int k = j + 1; k < sts[i].size(); k++) {
				int b = sts[i][k].first;
				intl tb = sts[i][k].second;
				if (a == b) continue;
				intl minti = min({dis[a][b], dis[b][a], ta + tb});
				dis[a][b] = dis[b][a] = minti;
			}
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	for (int i = 1; i <= q; i++) {
		int x, y; cin >> x >> y;
		intl ans = inf;
		for (int j = 0; j < sts[x].size(); j++) {
			int a = sts[x][j].first;
			intl ta = sts[x][j].second;
			for (int k = 0; k < sts[y].size(); k++) {
				int b = sts[y][k].first;
				intl tb = sts[y][k].second;
				ans = min(ans, dis[a][b] + ta + tb);
			}
		}
		ans += w[x] + w[y];
		cout << ans << '\n';
	}
	return 0;
}
