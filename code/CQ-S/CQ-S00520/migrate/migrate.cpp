#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;
int c, t, n, d, x[2000010], dis[2000010][3];
long long ans;
vector<int> e[2000010];
queue<pair<int, int> > q;

inline void bfs(int xx, int yy) {
	for (int i = 1; i <= n; i++) dis[i][0] = dis[i][1] = dis[i][2] = inf;
	dis[xx][0] = 0;
	while (q.size()) q.pop();
	q.push({xx, 0});
	while (q.size()) {
		int u = q.front().first, di = q.front().second;
		q.pop();
		for (auto v : e[u]) {
			if (di + 1 < dis[v][0])
				dis[v][0] = di + 1, q.push({v, dis[v][0]});
			else if (di + 1 < dis[v][1])
				dis[v][1] = di + 1, q.push({v, dis[v][1]});
			else if (di + 1 < dis[v][2])
				dis[v][2] = di + 1, q.push({v, dis[v][2]});
		}
	}
}

inline void solve() {
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++)
		scanf("%d", &x[i]), e[i].clear();
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n && x[j] - x[i] <= d; j++)
			e[i].push_back(j), e[j].push_back(i);
	ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			bfs(i, j);
			if (dis[j][0] == dis[j][1] && dis[j][2] != dis[j][1] && dis[j][0] != inf)
				ans++;
		}
	printf("%lld\n", ans);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--)
		solve();
	return 0;
}
