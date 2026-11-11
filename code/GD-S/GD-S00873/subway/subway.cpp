#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
const ll INF = 1e18;
int n, m, d, q, w[N];
vector<pair<int, int> > sub_line[N];
ll dis_line[504][504];
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> n >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			sub_line[a].push_back({i, t}); 
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				dis_line[i][j] = INF;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < (int)sub_line[i].size(); j++) {
			for (int k = 0; k < (int)sub_line[i].size(); k++) {
				if (j == k) continue;
				int u = sub_line[i][j].first, v = sub_line[i][k].first;
				dis_line[u][v] = dis_line[v][u] = 
					min(dis_line[u][v], (ll)sub_line[i][j].second + sub_line[i][k].second);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis_line[i][j] = min(dis_line[i][j], dis_line[i][k] + dis_line[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll ans = INF;
		for (auto pru : sub_line[x]) {
			for (auto prv : sub_line[y]) {
				int u = pru.first, v = prv.first;
				int du = pru.second, dv = prv.second;
				ans = min(ans, dis_line[u][v] + w[x] + w[y] + du + dv);
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
