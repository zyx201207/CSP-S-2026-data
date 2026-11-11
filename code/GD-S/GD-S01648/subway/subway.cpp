#include <bits/stdc++.h>
using namespace std;

long long read() {
	long long x = 0, k = 1; char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') k = -1, c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x * k;
}

const int K = 507;
const int N = 1e6 + 7;
const int M = 5e5 + 7;
const long long inf = 2e18;

int c, n, m, d, q, tot;
long long w[M];
long long dis[K][K];
vector<pair<int, long long> > conn[M]; 

void solve() {
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i ++) w[i] = read();
	for (int i = 1; i <= n; i ++) {
		int siz = read();
		for (int j = 1; j <= siz; j ++) {
			int id = read();
			long long wt = read();
			conn[id].push_back({i, wt});
		}
	} 
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			dis[i][j] = (i != j ? inf : 0);
	for (int i = 1; i <= m; i ++) {
		int siz = (int) conn[i].size();
		for (int x = 0; x < siz - 1; x ++)
			for (int y = x + 1; y < siz; y ++) {
				dis[conn[i][x].first][conn[i][y].first] = min(dis[conn[i][x].first][conn[i][y].first], conn[i][x].second + conn[i][y].second);
				dis[conn[i][y].first][conn[i][x].first] = min(dis[conn[i][y].first][conn[i][x].first], conn[i][x].second + conn[i][y].second);
			}
	}
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q --) {
		int u = read(), v = read();
		long long ans = 2e18;
		for (auto x : conn[u])
			for (auto y : conn[v])
				ans = min(ans, dis[x.first][y.first] + x.second + y.second);
		cout << ans + w[u] + w[v] << '\n';
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int qwq = 1;
//	qwq = read();
	while (qwq --)
		solve();
	return 0;
}

