#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 507, maxm = 500007;
const ll ee = 1e18;
int n, k, dis[maxn][maxn], vis[maxn], vis2[maxn], tt[maxn];
vector<int> edge[maxn];
void dfs(int u, int fa, int rt) {
	for (auto v : edge[u]) {
		if (v == fa) continue;
		dis[rt][v] = dis[rt][u] + 1, dfs(v, u, rt);
	}
}
void dfs2(int u, int fa) {
	vis2[u] = 1;
	for (auto v : edge[u]) {
		if (!vis[v] || v == fa) continue;
		dfs2(v, u);
	}
}
bool check(int S) {
	for (int i = 1; i <= n; i++) {
		vis[i] = (S >> (i - 1) & 1);
		vis2[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) dfs2(i, 0);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] && !vis2[i]) return 0;
	}
	return 1;
}
int solve(void) {
	for (int i = 1; i <= n; i++) {
		edge[i].clear();
	}
	cin >> n >> k;
	int ans = n + 10;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		edge[u].emplace_back(v);
		edge[v].emplace_back(u);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dis[i][j] = 0;
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, 0, i);
	}
	for (int S = 0; S < (1 << n); S++) {
		tt[S] = check(S);
	}
	for (int S = 0; S < (1 << n); S++) {
		for (int T = 0; T < (1 << n); T++) {
			if (S & T) continue;
			if (!tt[S] || !tt[T]) continue;
			int a1 = __builtin_popcount(S);
			int a2 = __builtin_popcount(T);
			if (a1 + a2 != k) continue;
			//cout << bitset<5>(S) << " " << bitset<5>(T) << ":::\n";
			int cur = 0;
			for (int i = 1; i <= n; i++) {
				int c2 = n + 10;
				for (int j = 1; j <= n; j++) {
					if ((S >> (j - 1) & 1) || (T >> (j - 1) & 1)) {
						c2 = min(c2, dis[i][j]);
						//cout << i << " " << j << " " << dis[i][j] << "\n";
					}
				}
				//cout << i << " " << c2 << "\n";
				cur = max(cur, c2);
			}
			ans = min(ans, cur);
		}
	}
	return ans;
}
int main(void) {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	int cid, T;
	cin >> cid >> T;
	for (; T--; ) {
		cout << solve() << "\n";
	}

	return 0;
}