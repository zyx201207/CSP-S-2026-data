#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, K, ans;
int dis[N][N], dist[N];
bool vis[N];
int fa[N];
inline int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
map <int, int> mp;
void chk() {
	int res = 0;
	for (int i = 1; i <= n; i++) fa[i] = 1;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			for (int j = 1; j <= n; j++) {
				if (vis[j] && i != j) {
					if (dis[i][j] <= 1) {
						fa[find(i)] = find(j);
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			mp[find(i)]++;
		}
	}
	if (mp.size() > 2) return mp.clear(), void();
	mp.clear();
	for (int i = 1; i <= n; i++) dist[i] = n + 1;
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			for (int j = 1; j <= n; j++)
				dist[j] = min(dist[j], dis[i][j]);
	}
	for (int i = 1; i <= n; i++) res = max(res, dist[i]);
	ans = min(ans, res);
}
void dfs(int j, int step) {
	if (K - step + 1 > n - j + 1) return;
	if (step == K + 1) return chk();
	for (int i = j; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			dfs(j + 1, step + 1);
			vis[i] = false;
		}
	}
}
void solve() {
	cin >> n >> K;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = n + 1;
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		dis[x][y] = dis[y][x] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	ans = n + 1;
	dfs(1, 1);
	cout << ans << '\n';
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int Tid, T; cin >> Tid >> T; while(T--) solve();
}
