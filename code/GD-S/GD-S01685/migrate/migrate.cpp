#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e6 + 10, M = 5010;

int c, t, n;
i64 d, x[N], dis[M][M], cnt[M][M];
vector<int> G[M];

i64 absll(i64 v) {
	return v >= 0LL ? v : -v;
}

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	if (c <= 10) {
		for (int i = 1; i <= n; i++)
			G[i] = vector<int>();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = -1, cnt[i][j] = 0;
				if (absll(x[i] - x[j]) <= d)
					G[i].emplace_back(j);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			queue<int> q;
			q.push(i), dis[i][i] = 0, cnt[i][i] = 1;
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (int v : G[u]) if (u != v) {
					if (dis[i][v] == -1)
						dis[i][v] = dis[i][u] + 1, cnt[i][v] = cnt[i][u], q.push(v);
					else if (dis[i][v] == dis[i][u] + 1)
						cnt[i][v] += cnt[i][u];
				}
			}
			for (int j = i + 1; j <= n; j++)
				ans += cnt[i][j] == 2;
		}
		cout << ans << "\n";
		return;
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
