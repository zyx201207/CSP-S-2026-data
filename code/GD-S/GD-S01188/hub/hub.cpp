#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int c, T, n, k, head[N], cnt, ans;
bool flag[N], vis[N];
struct edge {
	int nxt, to;
} e[N << 1];

void add(int u, int v) {
	e[++cnt] = {head[u], v};
	head[u] = cnt;
}

void dfs_1(int u, int fa) {
	vis[u] = 1;
	for (int i = head[u], v; i; i = e[i].nxt) {
		v = e[i].to;
		if (v == fa || !flag[v]) continue;
		dfs_1(v, u);
	}
}

int dfs_2(int u, int fa) {
	if (flag[u]) return 0;
	int d = -1;
	for (int i = head[u], v; i; i = e[i].nxt) {
		v = e[i].to;
		if (v == fa) continue;
		int tmp = dfs_2(v, u) + 1;
		if (tmp == 0) continue;
		if (d == -1 || tmp < d) d = tmp;
	}
	return d;
}

void dfs(int u, int tot) {
	if (tot == k) {
		int cnt_1 = 0, d = -1;
		for (int i = 1; i <= n; ++i) vis[i] = 0;
		for (int i = 1; i <= n; ++i) {
			if (flag[i] && !vis[i]) {
				cnt_1++;
				dfs_1(i, -1);
			}
		}
		if (cnt_1 > 2) return ;
		for (int i = 1; i <= n; ++i) {
			if (flag[i]) continue;
			int tmp = dfs_2(i, -1);
			if (d == -1 || tmp > d) d = tmp;
		}
		if (ans == -1 || d < ans) ans = d;
		return ;
	}
	if (u > n) return ;
	dfs(u + 1, tot);
	flag[u] = 1;
	dfs(u + 1, tot + 1);
	flag[u] = 0;
}

void init() {
	for (int i = 1; i <= n; ++i) head[i] = 0, flag[i] = vis[i] = 0;
	cnt = 0, ans = -1;
	scanf("%d%d", &n, &k);
	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
}

void solve() {
	init();
	dfs(1, 0);
	printf("%d\n", ans);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (T--) solve();
	return 0;
}
