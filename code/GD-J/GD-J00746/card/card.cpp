// difficulty: Blue / *2400
// tags: DP on tree / Ad-hoc
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500010];
int lst[500010], cnt[500010], dif[500010], siz[500010], ans[500010];
vector <int> G[500010];
void dfs(int u = n + 1, int f = 0) {
	siz[u] = 1;
	for (int v: G[u]) {
		if (v == f) continue;
		dfs(v);
		siz[u] += siz[v];
	}
	if (dif[u]) ans[dif[u]] += siz[u];
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i; i--) {
		int &l = lst[a[i]];
		if (l) G[l].emplace_back(i);
		else G[i + 1].emplace_back(i), dif[i] = a[i];
		l = i;
	}
	dfs();
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
