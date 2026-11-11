#include <bits/stdc++.h>
using namespace std;

const int N = 500, M = 500000;
const long long inf = 0x3f3f3f3f3f3f3f3fLL;

int _c, n, m, d, q, w[M + 10];
vector<pair<int, int>> a[M + 10];
long long dis[N + 10][N + 10];

int main() {
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> _c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k; cin >> k;
		while (k--) {
			int u, t; cin >> u >> t; a[u].push_back(make_pair(i, t));
		}
	}
	
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; ++i) dis[i][i] = 0;
	for (int i = 1; i <= m; ++i) {
		for (int u = 0; u < a[i].size(); ++u) {
			for (int v = u + 1; v < a[i].size(); ++v) {
				int x = a[i][u].first, y = a[i][v].first, z = a[i][u].second + a[i][v].second;
				dis[x][y] = min(dis[x][y], (long long)z), dis[y][x] = min(dis[y][x], (long long)z);
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	while (q--) {
		int x, y; cin >> x >> y; long long ans = inf;
		if (x == y) {cout << 0 << '\n'; continue;}
		for (int i = 0; i < a[x].size(); ++i) {
			for (int j = 0; j < a[y].size(); ++j) {
				ans = min(ans, dis[a[x][i].first][a[y][j].first] + (long long)(a[x][i].second + a[y][j].second));
			}
		}
		cout << ans + (long long)(w[x] + w[y]) << '\n';
	}
		
	return 0;
}

// chennie bless me

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/
