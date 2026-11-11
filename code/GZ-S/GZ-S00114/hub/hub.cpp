// GZ-S00114 安顺市第二高级中学 程泊郡
#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

int c, T, n, k, sz[N], zx, d[N];
vector<int> v[N];

void dfs(int fa, int s) {
	sz[s] = 1;
	int val = 0;
	for (int to : v[s]) {
		if (to == fa) continue;
		dfs(s, to);
		sz[s] += sz[to];
		val = max(val, sz[to]);
	}
	val = max(val, n - sz[s]);
	if (val <= n / 2) zx = s;
}

void dfs1(int s, int fa) {
	d[s] = d[fa] + 1;
	for (int to : v[s]) {
		if (to == fa) continue;
		dfs1(to, s);
	}
}

void dfs2(int s, int fa) {
	d[s] = min(d[s], d[fa] + 1);
	for (int to : v[s]) {
		if (to == fa) continue;
		dfs1(to, s);
	}
}

int check(int x, int y) {
	memset(d, 0, sizeof d);
	d[0] = -1;
	dfs1(x, 0);
	dfs2(y, 0);
	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res, d[i]);
	return res;
}

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(0, 1);
	int ans = n;
	for (int i : v[zx]) {
		ans = min(ans, check(i, zx));
	}
	printf("%d\n%d", ans, zx);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (T--) solve();
	return 0;
}
//0 2
//5 2
//1 2
//2 3
//3 4
//4 5
