#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e6 + 9;
int c, t, n, d, x[N], ans;
set <int> f[N], g[N];

inline ll read();

void dfs(int i, int deep) {
	if (f[i].count(deep)) {
		if (!g[i].count(deep)) {
			ans++;
			g[i].insert(deep);
		}
		return;
	}
	f[i].insert(deep);
	for (int j = i + 1; j <= n && x[i] + d >= x[j]; j++) {
		dfs(j, deep + 1);
	}
}

void solve() {
	n = read(), d = read();
	for (int i = 1; i <= n; i++) {
		x[i] = read();
		f[i].clear();
		g[i].clear();
	}
	ans = 0;
	dfs(1, 1);
	printf("%d\n", ans);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	while (t--) {
		solve();
	}
	return 0;
}

inline ll read() {
	ll w = 0, f = 1, c = getchar();
	while (!isdigit(c)) {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while (isdigit(c)) {
		w = w * 10 + (c ^ 48);
		c = getchar();
	}
	return w * f;
}
