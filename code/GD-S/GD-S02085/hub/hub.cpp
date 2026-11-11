#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int MAXN = 1e6 + 5;

template<typename T> void chkMin(T &x, T y) { x = y < x ? y : x; }
template<typename T> void chkMax(T &x, T y) { x = y > x ? y : x; }

int tid, tc, n, k, dis[MAXN], fa[MAXN];
int top, stk[MAXN];
bool mark[MAXN];
pii edges[MAXN];
vector<int> T[MAXN];

int solve(int x, int y, int mid) {
	int mxp = 0;
	auto dfs1 = [&](auto &&self, int u) -> void {
		if (!mxp || dis[u] > dis[mxp]) mxp = u;
		for (int v : T[u]) {
			if (v == fa[u] || (u == x && v == y)) continue;
			fa[v] = u;
			dis[v] = dis[u] + 1;
			self(self, v);
		}
	};
	
	dis[x] = fa[x] = 0;
	dfs1(dfs1, x);
	int P = mxp;
	dis[P] = fa[P] = mxp = 0;
	dfs1(dfs1, P);
	int Q = mxp;
	
	int t = dis[Q] >> 1, p = Q;
	for (int i = 1; i <= t; ++i) p = fa[p];
	if (mid >= (dis[Q] + 1 >> 1)) return 1;
	
	auto dfs2 = [&](auto &&self, int u, int fu) -> int {
		stk[++top] = u;
		if (top > mid) mark[stk[top - mid]] = true;
		int res = 0;
		for (int v : T[u]) {
			if (v == fu || (u == x && v == y)) continue;
			res += self(self, v, u);
		}
		--top;
		return res + mark[u];
	};
	
	top = 0;
	fill(mark + 1, mark + n + 1, false);
	int res = dfs2(dfs2, p, dis[Q] & 1 ? fa[p] : 0);
	if (dis[Q] & 1) {
		top = 0;
		fill(mark + 1, mark + n + 1, false);
		res += dfs2(dfs2, fa[p], p);
	}
	return res;
}

bool check(int mid) {
	if (solve(1, 0, mid) <= k) return true;
	for (int i = 1; i < n; ++i) {
		auto [u, v] = edges[i];
		if (solve(u, v, mid) + solve(v, u, mid) <= k) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> tid >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) T[i].clear();
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			T[u].emplace_back(v);
			T[v].emplace_back(u);
			edges[i] = {u, v};
		}
		
		int l = 0, r = n;
		while (l < r) {
			int mid = l + r >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		cout << l << '\n';
	}
	return 0;
}
