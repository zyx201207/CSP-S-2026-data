#include <bits/stdc++.h>

#define int long long

const int N = 5e5 + 7;

std::vector<int> G[N];

int dep[N], siz[N], hson[N], fa[N], mark[N];
int top[N];
int Case, T, n, m, k, ans;

void dfs1(int x, int Fa) {
	dep[x] = dep[fa[x] = Fa] + 1; siz[x] = 1;
	for (int y : G[x]) {
		if (y != Fa) {
			dfs1(y, x);
			siz[x] += siz[y]; if (siz[y] > siz[hson[x]]) hson[x] = y; 
		}
	}
}
void dfs2(int x, int Top) {
	top[x] = Top; if (hson[x]) dfs2(hson[x], Top);
	for (int y : G[x]) if (y != fa[x] && y != hson[x]) dfs2(y, y);
}
int LCA(int x, int y) {
	for (; top[x] != top[y]; x = fa[top[x]]) if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
	return dep[x] < dep[y] ? x : y;
}

void Solve() {
	int Res = 0;
	for (int i = 1; i <= n; i ++) {
		if (mark[i]) continue;
		int res = 1e18;
		for (int j = 1; j <= n; j ++)
			if (mark[j]) res = std::min(res, dep[i] + dep[j] - 2 * dep[LCA(i, j)]);
		Res += res;
	}
	ans = std::max(ans, Res);
}

void dfs(int x, int sum) {
	if (sum == k) return Solve();
	if (x > n) return;
	mark[x] = 1; dfs(x + 1, sum + 1);
	mark[x] = 0; dfs(x + 1, sum);
}

void solve() {
	ans = 0;
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i ++) G[i].clear(), dep[i] = siz[i] = hson[i] = fa[i] = mark[i] = top[i] = 0;
	for (int i = 1, x, y; i < n; i ++) scanf("%lld%lld", &x, &y), G[x].push_back(y), G[y].push_back(x);
	dfs1(1, 0); dfs2(1, 1);
	dfs(1, 0); printf("%lld\n", ans);
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout); 

	for (scanf("%lld%lld", &Case, &T); T --; ) solve();
	
	return 0;
} 
