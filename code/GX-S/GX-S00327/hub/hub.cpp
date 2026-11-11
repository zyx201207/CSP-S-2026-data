#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read() {
	ll x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = 0;
		}
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	if (f) {
		return x;
	}
	return -x;
}
inline void write(ll s) {
	if (s < 10) {
		putchar(s ^ 48);
		return ;
	}
	write(s / 10);
	putchar(s % 10 ^ 48);
}
int c, T, n, k, vis[11], now, res, ans;
vector<int> g[15];
void dfs2(int x, int fa, vector<int> xz) {
	if (vis[x]) {
		return ;
	}
	vis[x] = 1;
	for (int y : g[x]) {
		if (y == fa) {
			continue;
		}
		int idx = lower_bound(xz.begin(), xz.end(), y) - xz.begin();
		if (idx != k && xz[idx] == y) {
			dfs2(y, x, xz);
		}
	}
}
void dfs3(int x, int fa, vector<int> xz, int len) {
	if (vis[x]) {
		return ;
	}
	vis[x] = 1;
	int idx = lower_bound(xz.begin(), xz.end(), x) - xz.begin();
	if (idx != k && xz[idx] == x) {
		now = min(now, len);
		return ;
	}
	for (int y : g[x]) {
		if (y == fa) {
			continue;
		}
		dfs3(y, x, xz, len + 1);
	}
}
void dfs(int idx, vector<int> xz) {
	if ((int)(xz.size()) == k) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			vis[i] = 0;
		}
		for (int x : xz) {
			if (!vis[x]) {
				dfs2(x, 0, xz);
				cnt++;
			}
		}
		if (cnt > 2) {
			return ;
		}
		res = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				vis[j] = 0;
			}
			now = n + 1;
			dfs3(i, 0, xz, 0);
			res = max(res, now);
		}
		ans = min(ans, res);
		return ;
	}
	if (idx > n) {
		return ;
	}
	xz.push_back(idx);
	dfs(idx + 1, xz);
	xz.pop_back();
	dfs(idx + 1, xz);
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c = read();
	T = read();
	while (T--) {
		ans = n + 1;
		n = read(), k = read();
		for (int i = 1; i <= n; i++) {
			g[i].clear();
		}
		for (int i = 1; i < n; i++) {
			int u, v;
			u = read(), v = read();
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<int> kong;
		dfs(1, kong);
		write(ans);
		putchar('\n');
	}
	return 0;
}
