#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
constexpr int maxn = 5000 + 10;
ll a[maxn], dis[maxn][maxn], cnt[maxn][maxn]; int vis[maxn];
vector <int> e[maxn];
void dijk (int s, int n) {
	priority_queue <pair <int, int> > pq;
	for (int j = 1; j <= n; j ++) vis[j] = 0, dis[s][j] = 1e9, cnt[s][j] = 0;
	dis[s][s] = 0, cnt[s][s] = 1; pq.push({0, s});
	while (pq.size() > 0) {
		int tp = pq.top().second; pq.pop();
		if (vis[tp] == 1) continue;
		vis[tp] = 1;
		for (int v : e[tp]) {
			if (dis[s][v] > dis[s][tp] + 1) {
				dis[s][v] = dis[s][tp] + 1;
				cnt[s][v] = cnt[s][tp];
				pq.push({-dis[s][v], v});
			} else if (dis[s][v] == dis[s][tp] + 1) {
				cnt[s][v] += cnt[s][tp];
				if (cnt[s][v] > 2) cnt[s][v] = 3;
			}
		}
	}
}
void solve () {
	int n; ll d; cin >> n >> d;
	for (int i = 1; i <= n; i ++) e[i].resize(0), cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			if (a[j] - a[i] <= d) e[i].push_back(j);
		}
	}
//	cout << "1\n";
	for (int i = 1; i <= n; i ++) dijk(i, n);
//	int ans = 0; cout << "2\n";
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (cnt[i][j] == 2) ans ++;
		}
	} cout << ans << '\n';
}
signed main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int c, tid; cin >> c >> tid;
	while (tid --) {
		solve();
	}
}
