#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, M = 2e6 + 5;
int c, T, n, m, k, head[N], tot, dis[N], fa[N], Fa[N], rt, mxd, id[N], mx[N];
bool flg, vis[N];
struct edge {int v, nxt;} e[M];
void add(int u, int v) {e[++tot] = {v, head[u]}, head[u] = tot;}
struct node {
	int u, d;
	bool operator < (const node &y) const {return d > y.d;}
};
priority_queue<node> Q;
int dij(bool f, int s1, int s2) {
	while (!Q.empty()) Q.pop();
	for (int i = 1; i <= n; i++) dis[i] = 1e9, vis[i] = 0;
	if (f == 0) {
		for (int i = 1; i <= n; i++) if (s1 & (1 << (i - 1))) dis[i] = 0, Q.push({i, dis[i]});
	}
	else {
		if (s1) dis[s1] = 0, Q.push({s1, dis[s1]});
		if (s2) dis[s2] = 0, Q.push({s2, dis[s2]});
	}
	while (!Q.empty()) {
		int u = Q.top().u; Q.pop();
		if (vis[u]) continue; vis[u] = 1;
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v;
			if (dis[v] <= dis[u] + 1) continue;
			dis[v] = dis[u] + 1, Q.push({v, dis[v]});
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, dis[i]);
	return ans;
}
int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
bool check(int s) {
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= n; i++) {
		if (!(s & (1 << (i - 1)))) continue;
		for (int j = head[i]; j; j = e[j].nxt) {
			int v = e[j].v;
			if (!(s & (1 << (v - 1)))) continue;
			fa[find(i)] = find(v);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) if ((s & (1 << (i - 1))) && find(i) == i) cnt++;
	return (cnt <= 2);
}
void get_d(int u, int fa, int dis) {
	if (dis > mxd) rt = u;
	Fa[u] = fa;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v; if (v == fa) continue;
		get_d(v, u, dis + 1);
	}
}
int get_w(int u, int fa, int dis, int &s) {
	mx[u] = 0;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v; if (v == fa) continue;
		int now = get_w(v, u, dis + 1, s);
		mx[u] = max(mx[u], now);
	}
	int ans = mx[u] + 1;
	mx[u] = max(mx[u], dis);
	if (!s || mx[u] < mx[s]) s = u;
	return ans;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k, m = (n - 1) / 2, flg = 1, memset(head, 0, sizeof(head)), tot = 0;
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v, add(u, v), add(v, u);
			if (i <= m && (u != i || v != i + 1)) flg = 0;
			if (i > m && (u != i - m || v != i + 1)) flg = 0;
		}
		if (flg) {cout << max(1, ((m + 2 + 1) / 2 - k / 2 + 1) / 2) << '\n'; continue;}
		if (n <= 10) {
			int ans = 1e9;
			for (int s = 1; s < (1 << n); s++) {
				if (__builtin_popcount(s) != k || !check(s)) continue;
				ans = min(ans, dij(0, s, 0));
			}
			cout << ans << '\n';
		}
		else {
			mxd = 0, get_d(1, 0, 0); int nd = rt; mxd = 0, get_d(rt, 0, 0);
			int sum = 0, s1 = 0, s2 = 0;
			for (int i = rt; i != nd; i = Fa[i]) id[++sum] = i;
			int delu = id[sum / 2], delv = id[sum / 2 + 1];
			get_w(delu, delv, 0, s1), get_w(delv, delu, 0, s2);
			cout << dij(1, s1, s2) << '\n';
		}
	}
	return 0;
}