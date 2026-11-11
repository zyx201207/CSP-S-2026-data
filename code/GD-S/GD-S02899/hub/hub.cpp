#include <bits/stdc++.h>
#define rd read()
#define fi first
#define se second
#define pii pair<int, int>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;
const int N = 5 + 1e6;
int c, t, n, k, dep[N], f[N][25], ans, block;
vector<int> e[N], cr;
bool chose[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
void write(int x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void init() {
	rep(i, 1, n) while (!e[i].empty()) e[i].pop_back();
	memset(f, 0, sizeof f);
	memset(chose, 0, sizeof chose);
	memset(dep, 0, sizeof dep);
	while (!cr.empty()) cr.pop_back();
}
void dfs(int x, int fa) {
	f[x][0] = fa;
	dep[x] = dep[fa] + 1;
	for (int i = 1; i <= 20; i++) f[x][i] = f[f[x][i - 1]][i - 1];
	for (auto v : e[x]) {
		if (v != fa) dfs(v, x);
	}
}
int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; ~i; i--) {
		if (dep[f[x][i]] >= dep[y]) {
			x = f[x][i];
		}
	}
	if (x == y) return x;
	for (int i = 20; ~i; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
void dfa(int x, int fa) {
	if (chose[x]) block += !chose[fa];
	if (block > 2) return;
	for (auto i : e[x]) {
		if (i != fa) dfa(i, x);
	}
}
void sed() {
	block = 0;
	dfa(1, 0);
	if (block > 2) return;
	while (!cr.empty()) cr.pop_back();
	rep(i, 1, n) {
		if (chose[i]) cr.emplace_back(i);
	}
	int res = 0;
	rep(i, 1, n) {
		if (chose[i]) continue;
		int mn = INT_MAX;
		for (auto j : cr) {
			int u = i, v = j;
			int lc = lca(u, v);
			int dis = dep[u] + dep[v] - 2 * dep[lc];
			mn = min(mn, dis);
		}
		res = max(res, mn);
	}
	ans = min(ans, res);
}
void chs(int x, int has) {
	if (has > k) return;
	if (has == k) {
		sed();
		return;
	}
	if (x > n) return;
	chose[x] = 1;
	chs(x + 1, has + 1);
	chose[x] = 0;
	chs(x + 1, has);
}
void solve() {
	n = rd; k = rd;
	init();
	rep(i, 2, n) {
		int u = rd, v = rd;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ans = INT_MAX;
	dfs(1, 0);
	chs(1, 0);
	write(ans), putchar('\n');
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c = rd; t = rd;
	while (t--) solve();
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
