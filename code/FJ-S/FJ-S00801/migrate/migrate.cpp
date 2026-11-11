#include <bits/stdc++.h>
using namespace std;

long long dis[5005][5005], x[2000005], c, t, n, d, ans, tot, w;
vector<long long> e[2000005];

void dfs(long long u, long long fa, long long sum, long long end, long long diss) {
	if (u == end && sum == diss) {
		tot++;
		return;
	}
	if (sum >= diss) return;
	for (auto i : e[u]) {
		if (i != fa) dfs(i, u, sum + 1, end, diss);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ans = 0;
		cin >> n >> d;
		for (long long i = 0; i <= n; i++) e[i].clear();
		for (long long i = 0; i <= n; i++) {
			for (long long j = 0; j <= n; j++) dis[i][j] = 1e18;
		}
		for (long long i = 1; i <= n; i++) cin >> x[i];
		if (n < 301) {
			for (long long i = 1; i <= n; i++) {
				for (long long j = i + 1; j <= n; j++) {
					if (x[j] - x[i] <= d) {
						e[i].push_back(j);
						e[j].push_back(i);
						dis[i][j] = dis[j][i] = 1;
					}
				}
			}
			for (long long i = 0; i <= n; i++) dis[i][i] = 0;
			for (long long k = 1; k <= n; k++) {
				for (long long i = 1; i <= n; i++) {
					for (long long j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
			for (long long i = 1; i <= n; i++) {
				for (long long j = i + 1; j <= n; j++) {
					tot = 0;
					w = dis[i][j];
					if (dis[i][j] >= 1e18) continue;
					dfs(i, i, 0, j, w);
					if (tot == 2) ans++;
				}
			}
			cout << ans << endl;
		} else cout << "0\n";
	}
	return 0;
}
