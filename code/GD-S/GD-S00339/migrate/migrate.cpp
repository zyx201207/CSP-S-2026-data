#include <bits/stdc++.h>
#define lc ((u) << 1)
#define rc (((u) << 1) | 1)
using namespace std;
using ll = long long;
const int maxn = 2e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
vector <pair<int, int> > g[maxn*4];
ll x[maxn], cnt[maxn*4], dis[maxn*4];
int id[maxn], tot, qx, qy, qk;
void build(int u, int l, int r) {
	tot = max(tot, u);
	if (l == r) {
		id[l] = u;
		return;
	}
	g[u].push_back({lc, 0});
	g[u].push_back({rc, 0});
	int mid = (l + r) / 2;
	build(lc, l, mid);
	build(rc, mid + 1, r);
}
void add(int u, int l, int r) {
	if (qx <= l && r <= qy) {
		g[qk].push_back({u, 1});
		return;
	}
	int mid = (l + r) / 2;
	if (qx <= mid) add(lc, l, mid);
	if (qy > mid) add(rc, mid + 1, r);
}
void bfs(int s) {
	deque <int> q;
	dis[s] = 0; q.push_front(s); cnt[s] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop_front();
		for (auto p : g[u]) {
			int v = p.first, w = p.second;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				cnt[v] = cnt[u];
				if (!w) q.push_front(v);
				else q.push_back(v);
			} else if (dis[u] + w == dis[v]) cnt[v] += cnt[u];
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--) {
		int n;
		ll d;
		cin >> n >> d;
		if (n > 5000) {
			cout << "0\n";
			continue;
		}
		for (int i = 1; i <= n; i++) cin >> x[i];
//		build(1, 1, n);
//		for (int i = 1; i <= n; i++) {
//			qx = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
//			qy = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
//			qk = id[i];
//			add(1, 1, n);
//		}
		tot = n;
		for (int i = 1; i <= n; i++) {
			id[i] = i;
			qx = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
			qy = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
			for (int j = qx; j <= qy; j++) g[i].push_back({j, 1});
		}
//		for (int i = 1; i <= tot; i++) {
//			cout << i << ": ";
//			for (auto j : g[i]) cout << j.first << " " << j.second << "/";
//			cout << "\n";
//		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= tot; j++) dis[j] = inf, cnt[j] = 0;
			bfs(id[i]);
			for (int j = 1; j <= n; j++) if (cnt[id[j]] == 2) ans++;
		}
//		for (auto p : st) cout << p.first << " " << p.second << "\n";
		cout << ans / 2 << "\n";
		for (int i = 1; i <= tot; i++) g[i].clear();
	}
	return 0;
}

