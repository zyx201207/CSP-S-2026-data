#include <bits/stdc++.h>

const int N = 1e6 + 7, inf = 1e9;

int n, k;
std::vector<int> G[N];

int f[N];
void dfs0(int u, int fa) {
	f[u] = fa;
	for (int v : G[u])
		if (v != fa)
			dfs0(v, u);
}
int mxd[N], dep[N], fd[N];
void dfs(int u, int fa, int p) {
	mxd[u] = dep[u] = dep[fa] + 1;
	int res = 0;
	for (int v : G[u])
		if (v != fa && v != p)
			res += dfs(v, u, p), mxd[u] = std::max(mxd[u], mxd[v]);
}
int pre[N], suf[N], mx[N];
void dfs2(int u, int fa, int mfd, int p) {
	fd[u] = mfd;
	int res = 0;
	pre[G[u][0]] = 0;
	for (int i = 1; i < G[u].size(); ++i) {
		int v = G[u][i - 1];
		if (v != fa && v != p)
			pre[G[u][i]] = std::max(pre[v], mxd[v] + 1 - dep[u]);
		else
			pre[G[u][i]] = pre[v];
	}
	suf[G[u].back()] = 0;
	for (int i = G[u].size() - 1; i >= 0; ++i) {
		int v = G[u][i + 1];
		if (v != fa && v != p)
			suf[G[u][i]] = std::max(suf[v], mxd[v] + 1 - dep[u]);
		else
			suf[G[u][i]] = suf[v];
	}
	for (int v : G[u])
		if (v != fa && v != p)
			mx[v] = std::max(pre[v], suf[v]);
	for (int v : G[u])
		if (v != fa && v != p)
			res += dfs2(v, u, std::max(mfd, mx[v]) + 1, p);
}
int mxa[N];
int calc() {
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			if (mxa[i] >= mid)
				++cnt;
	}
}

void solve() {
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) G[i].clear();
	for (int i = 1, u, v; i < n; ++i)
		std::cin >> u >> v, G[u].push_bac(v), G[v].push_back(u);
	for (int i = 2; i <= n; ++i) {
		dfs(1, 0, i), dfs2(1, 0, 0, f[i]);
		for (int j = 1; j <= n; ++j)
			mxa[j] = std::max(mxd[i] - dep[i], fd[i]);
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	std::cin.tie(0), std::cout.tie(0), std::ios::sync_with_stdio(false);
	
	return 0;
}
