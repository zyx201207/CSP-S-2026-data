#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000010;
int C, T;
int n, k, a[N], vis[N], ans, dis[N];
vector <int> v[N];
void dfs(int x) {
	vis[x] = 1;
	for (auto i : v[x]) {
		if (vis[i] || a[i] == 0) continue;
		dfs(i);
	}
}
bool check() {
	for (int i = 1; i <= n; i++) vis[i] = 0;
	int cnt = 0, sum = 0;
	for (int i = 1; i <= n; i++) sum += a[i];
	if (sum != k) return 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1 && !vis[i]) {
			dfs(i);
			cnt++;
		}
		if (cnt > 2) return 0;
	}
	return 1;
}
struct tt {
	int x, dis;
	friend bool operator < (tt a, tt b) {
		return a.dis > b.dis;
	}
};
priority_queue <tt> q;
void bfs() {
	while (q.size()) q.pop();
	for (int i = 1; i <= n; i++) {
		dis[i] = 1e9;
		vis[i] = 0;
		if (a[i]) {
			dis[i] = 0;
			vis[i] = 1;
			q.push({i, 0});
		}
	}
	while (q.size()) {
		tt op = q.top();
		q.pop();
		if (vis[op.x] == 0) continue;
		vis[op.x] = 0;
		for (auto i : v[op.x]) {
			if (dis[i] > op.dis + 1) {
				dis[i] = op.dis + 1;
				q.push({i, dis[i]});
				vis[i] = 1;
			}
		}
	}
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, dis[i]);
	}
	ans = min(ans, mx);
}
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) v[i].clear();
	for (int i = 1, x, y; i < n; i++) {
		scanf("%lld%lld", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	ans = 1e18;
	for (int S = 0; S < (1 << n) - 1; S++) {
		for (int i = 1; i <= n; i++) {
			if (S & (1 << (i - 1))) a[i] = 1;
			else a[i] = 0;
		}
		if (check()) {
			bfs();
		}
	}
	cout << ans << "\n";
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> C >> T;
	while (T--) {
		solve();
	}
}
