#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;
const ll mod = 998244353;
const ll P = 1e9 + 7;
const int N = 5e5 + 5, M = 505;
const ll inf = 1e18;
int c, n, m, d, q, w[N];
ll dis[M][M];// 线路 a 与线路 b 之间的换乘的代价 
vector <pii> v[N];// 哪些线路经过地铁站 a，该站台到站厅所用时间 

int main () {
	ios :: sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);

	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++)
		cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j ++) {
			int a, t;
			cin >> a >> t;
			v[a].push_back ({i, t});
		}
	}
	for (int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++) {
			dis[i][j] = inf;
			if (i == j)
				dis[i][j] = 0;
		}
	for (int i = 1; i <= m; i ++) {
		for (int ai = 0; ai < v[i].size (); ai ++)
			for (int bi = ai + 1; bi < v[i].size (); bi ++) {
				int a = v[i][ai].first, at = v[i][ai].second;
				int b = v[i][bi].first, bt = v[i][bi].second;
				dis[b][a] = dis[a][b] = at + bt;
			}
	}
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = i + 1; j <= n; j ++)
				if (dis[i][k] != inf && dis[k][j] != inf)
					dis[j][i] = dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
	while (q --) {
		int a, b;
		cin >> a >> b;
		ll ans = 1e18;
		for (int ai = 0; ai < v[a].size (); ai ++)
			for (int bi = 0; bi < v[b].size (); bi ++) {
				int azt = v[a][ai].first, at = v[a][ai].second;
				int bzt = v[b][bi].first, bt = v[b][bi].second;
				ans = min (ans, at + dis[azt][bzt] + bt);
			}
		ans += w[a] + w[b];
		cout << ans << "\n";
	}
	return 0;
}

