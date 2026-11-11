#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6;
int t;
int n, m;
class graph {
	private:
	int idx;
	public:
	int head[N + 5];
	struct edge {
		int nxt, v;
	} e[(N << 1) + 5];
	void init(int n) {
		memset(head + 1, 0, n * sizeof(int));
		idx = 0;
	}
	constexpr void add_dir(int u, int v) {
		e[++idx] = {head[u], v};
		head[u] = idx;
	}
	constexpr void add_udir(int u, int v) {
		add_dir(u, v), add_dir(v, u);
	}
} g;
int dep[N + 5], fa[N + 5], root;
int a[N + 5], cnt;
bool vis[N + 5];
int val[N + 5], lroot[N + 5], rroot[N + 5];
int pre[N + 5], nxt[N + 5];
int res[N + 5];
template<typename T>
inline void read(T &x) {
	x = 0;
	int ch = getchar();
	while (ch < 48 || ch > 57) ch = getchar();
	while (ch >= 48 && ch <= 57) {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
}
void dfs1(int u) {
	dep[u] = dep[fa[u]] + 1;
	if (dep[root] < dep[u]) root = u;
	for (int i = g.head[u]; i; i = g.e[i].nxt) {
		int v = g.e[i].v;
		if (v == fa[u]) continue;
		fa[v] = u;
		dfs1(v);
	}
}
void dfs2(int u) {
	dep[u] = 1;
	for (int i = g.head[u]; i; i = g.e[i].nxt) {
		int v = g.e[i].v;
		if (v == fa[u] || vis[v]) continue;
		fa[v] = u;
		dfs2(v);
		dep[u] = max(dep[u], dep[v] + 1);
	}
}
bool check(int mid) {
	memset(res + 1, 0, (cnt - 1) * sizeof(int));
	int tot = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i]) tot += dep[i] > mid;
	for (int i = cnt, j = cnt; i >= 1; i--) {
		j = min(j, i);
		while (j && dep[a[j]] + i - j <= mid) j--;
		pre[i] = j;
	}
	for (int i = 1, j = 1; i <= cnt; i++) {
		j = max(j, i);
		while (j <= cnt && dep[a[j]] + j - i <= mid) j++;
		nxt[i] = j;
	}
	for (int i = 1, l1 = 1, l2 = 1, r1 = 1, r2 = 1; i <= cnt; i++) {
		while (l1 < i && rroot[l1 + 1] < i) l1++;
		while (l2 < i && rroot[l2 + 1] <= i) l2++;
		while (r1 < cnt && lroot[r1] < i) r1++;
		while (r2 < cnt && lroot[r2] <= i) r2++;
		if (nxt[i] <= cnt) res[1]++, res[l2]--;
		else res[l1]++, res[l2]--;
		int x = max(l2, pre[i]);
		res[l2]++, res[x]--;
		if (pre[i]) res[r1]++;
		else res[r1]++, res[r2]--;
		x = min(r1, nxt[i]);
		res[x]++, res[r1]--;
	}
	for (int i = 1; i < cnt; i++) {
		res[i] += res[i - 1];
		if (tot + res[i] <= m) return true;
	}
	return false;
}
int binary() {
	int l = 0, r = n / 3;
	while (l < r) {
		int mid = l + r >> 1;
		check(mid) ? r = mid : l = mid + 1;
	}
	return l;
}
void solve() {
	cnt = 0;
	read(n), read(m);
	g.init(n);
	memset(vis + 1, 0, n * sizeof(bool));
	for (int _ = 1; _ < n; _++) {
		int u, v;
		read(u), read(v);
		g.add_udir(u, v);
	}
	fa[1] = root = 0, dfs1(1);
	int x = root;
	fa[root] = 0, dfs1(root);
	for (int i = root; i != x; i = fa[i]) a[++cnt] = i;
	a[++cnt] = x;
	for (int i = 1; i <= cnt; i++) vis[a[i]] = true;
	for (int i = 1; i <= cnt; i++) dfs2(a[i]);
	for (int i = 1; i <= cnt; i++) {
		int tmp = i + dep[a[i]];
		val[i] = max(val[i - 1], tmp);
		lroot[i] = tmp <= val[i - 1] ? lroot[i - 1] : tmp >> 1;
	}
	val[cnt + 1] = 0;
	for (int i = cnt; i >= 1; i--) {
		int tmp = cnt - i + 1 + dep[a[i]];
		val[i] = max(val[i + 1], tmp);
		rroot[i] = tmp <= val[i + 1] ? rroot[i + 1] : cnt - (tmp >> 1) + 1;
	}
	cout << binary() << '\n';
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	read(t), read(t);
	while (t--) solve();
	return 0;
}

