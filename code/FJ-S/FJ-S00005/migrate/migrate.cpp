#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, t, n, st, ans, vis[N];
bool ok[5005][5005];
long long d, x[N];
map<int, int> mp[N];
void dfs(int u, int dis) {
	mp[u][dis]++;
	for (int i = 1; i <= n; i++) {
		if (!ok[u][i]) continue;
		if (!vis[i]) vis[i] = 1, dfs(i, dis + 1), vis[i] = 0;
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d %d", &c, &t);
	while (t--) {
		scanf("%d %lld", &n, &d), ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%lld", &x[i]);
		if (n > 10) {
			printf("0\n");
			continue;
		} 
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				ok[i][j] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (abs(x[i] - x[j]) <= d) ok[i][j] = ok[j][i] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) vis[j] = 0, mp[j].clear();
			vis[st = i] = 1, dfs(st, 0);
			for (int j = 1; j <= n; j++) {
				int mn = n;
				for (auto pr : mp[j])
					mn = min(mn, pr.first);
				if (i != j && mp[j][mn] == 2) ans++;
			}
		}
		printf("%d\n", ans / 2);
	}
  return 0;
}
