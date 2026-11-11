#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1e9;
int n, dis[5010][5010], cnt[5010][5010];
ll d, xp[200010];
vector<int> e[200010];

void solve() {
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &xp[i]);
	}
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (llabs(xp[i] - xp[j]) <= d) {
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = inf; cnt[i][j] = 0;
		}
		dis[i][i] = 0;
		queue<int> q; q.push(i);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (auto y : e[x]) {
				if (dis[i][x] + 1 < dis[i][y]) {
					dis[i][y] = dis[i][x] + 1;
					cnt[i][y] = 1; q.push(y);
				} else if (dis[i][x] + 1 == dis[i][y]) {
					cnt[i][y]++; q.push(y); 
				}
			}
		}
	}
	int ans = 0;
	for (int u = 1; u <= n; u++) {
		for (int v = u + 1; v <= n; v++) {
			ans += dis[u][v] < inf && cnt[u][v] == 2;
		}
	}
	printf("%d\n", ans);
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int test, c;
	scanf("%d%d", &c, &test);
	while (test--) solve();
	return 0;
}

