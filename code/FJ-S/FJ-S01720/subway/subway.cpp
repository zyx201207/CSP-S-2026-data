# include<bits/stdc++.h>

# define int long long

using namespace std;

const int Inf = 1e17;
const int N = 500005;
const int M = 505;

int c, n, m, d, q, ans;
int w[N], dis[M][M];
vector<pair<int, int> > to[N];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0) -> ios :: sync_with_stdio(false);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++)
		cin >> w[i];

	int k;
	for (int i = 1; i <= n; i ++) {
		cin >> k;
		int x, y;
		for (int j = 0; j < k; j ++) {
			cin >> x >> y;
			to[x].push_back({i, y});
		}
	}

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			dis[i][j] = Inf;
	for (int i = 1; i <= n; i ++)
		dis[i][i] = 0;

	for (int i = 1; i <= m; i ++) {
		int sz = to[i].size(), x, y, u, v;
		for (int j = 0; j < sz; j ++) {
			x = to[i][j].first, u = to[i][j].second;
			for (int k = 0; k < sz; k ++) {
				y = to[i][k].first, v = to[i][k].second;
				dis[x][y] = min(dis[x][y], u + v);
				dis[y][x] = min(dis[y][x], v + u);
			}
		}
	}

	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

	int x, y, sx, sy;
	for (int i = 1; i <= q; i ++) {
		cin >> x >> y;
		sx = to[x].size(), sy = to[y].size();
		ans = Inf;
		for (int j = 0; j < sx; j ++)
			for (int k = 0; k < sy; k ++)
				ans = min(ans, to[x][j].second + to[y][k].second + dis[to[x][j].first][to[y][k].first]);
		cout << ans + w[x] + w[y] << "\n";
	}

	return 0;
}