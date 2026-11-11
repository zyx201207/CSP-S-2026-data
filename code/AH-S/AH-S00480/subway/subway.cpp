#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
const int inf = 0x3f3f3f3f3f3f33f;
int c, n, m, d, q, w[N], dis[505][505];
struct edge {
	int v, w;
};
vector <edge> G[505];
struct node {
	int i, d;
};
vector <node> v[N];
inline void init() {
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i++) 
		for (int j = 0; j < v[i].size(); j++)
			for (int k = 0; k < v[i].size(); k++) 
				dis[v[i][j].i][v[i][k].i] = v[i][j].d + v[i][k].d;
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) 
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, k, a, t; i <= n; i++) {
		cin >> k;
		while (k--) cin >> a >> t, v[a].push_back({i, t});
	}
	init();
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = inf;
		for (int i = 0; i < v[x].size(); i++)
			for (int j = 0; j < v[x].size(); j++) 
				ans = min(ans, dis[v[x][i].i][v[y][j].i] + v[x][i].d + v[y][j].d);
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
