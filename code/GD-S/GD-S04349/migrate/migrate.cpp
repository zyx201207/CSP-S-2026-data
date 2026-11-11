#include<bits/stdc++.h>
using namespace std;
int c, t, dis[2000005], cnt[2000005];
long long x[2000005];
vector<int> f[2000005];
bool vis[2000005];
priority_queue<pair<int, int> > q;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		int n;
		long long d;
		cin >> n >> d;
		for (int i = 1;i <= n;i++) {
			cin >> x[i];
		}
		if (n <= 3) {
			cout << 0 << '\n';
			continue;
		}
		if (n <= 5000) {
			for (int i = 1;i <= n;i++) {
				f[i].clear();
			}
			for (int i = 1;i < n;i++) {
				for (int j = i + 1;j <= n;j++) {
					if (x[j] - x[i] <= d) {
						f[i].push_back(j);
					}
				}
			}
			long long ans = 0;
			for (int i = 1;i <= n;i++) {
				for (int j = 1;j <= n;j++) {
					dis[j] = 1e9;
					cnt[j] = 0;
					vis[j] = 0;
				}
				dis[i] = 0;
				cnt[i] = 1;
				q.push({0, i});
				while (!q.empty()) {
					int u = q.top().second;
					q.pop();
					if (vis[u]) continue;
					vis[u] = 1;
					for (int j = 0;j < f[u].size();j++) {
						int v = f[u][j];
						if (dis[v] > dis[u] + 1) {
							dis[v] = dis[u] + 1;
							cnt[v] = min(cnt[u], 3);
							q.push({-dis[v], v});
						}
						else if (dis[v] == dis[u] + 1) {
							cnt[v] = min(cnt[u] + cnt[v], 3);
						}
					}
				}
				for (int i = 1;i <= n;i++) {
					if (cnt[i] == 2) {
						ans++;
					}
				}
			}
			cout << ans << '\n';
			continue;
		}
		long long dif = x[2] - x[1], len = d / dif;
		if (len <= 1 || 2 * len > n) {
			cout << 0 << '\n';
		}
		else {
			cout << n - 2 * len + 1 << '\n';
		}
	}
	return 0;
}
