#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, x[305], dis[305][305], ans, cnt;
vector <int> g[305];
void dfs(int u, int num, int ed, int sm) {
	if (u == ed && sm == num) ans++;
	if (ans > 2) return;
	for (int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i];
		dfs(v, num, ed, sm + 1);
	}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		memset(dis, 0x3f, sizeof dis);
		for (int i = 1; i <= n; i++)
			g[i].clear();
		cnt = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		if (c >= 7) {
			cout << 0 << "\n";
			continue;
		}
		for (int i = 1; i <= n; i++)
			dis[i][i] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (x[j] - x[i] <= d) {
					dis[i][j] = dis[j][i] = 1;
					g[i].push_back(j);
				}
		for (int i = 1; i <= n; i++)
			dis[i][i] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				for (int k = i + 1; k < j; k++)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				ans = 0;
				dfs(i, dis[i][j], j, 0);
				if (ans == 2) cnt++;
			}
		cout << cnt << "\n";	
	}
	return 0;
}
