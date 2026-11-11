#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m, a[N];
bool to[N], is[N];
int sz[N], ans[M];
vector<int> pos[M], g[N];
void dfs(int x, int fa) {
	sz[x] = 1;
	for (auto i : g[x]) {
		if (i == fa) continue;
		dfs(i, x);
		sz[x] += sz[i];
	}
	if (is[x]) ans[a[x]] = sz[x];
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]].push_back(i);
	}
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j < (int)pos[i].size(); j++) {
			int u = pos[i][j - 1], v = pos[i][j];
			to[u] = true;
			g[u].push_back(v);
			g[v].push_back(u);
		}
	for (int i = 1; i < n; i++)
		if (!to[i]) {
			g[i].push_back(i + 1);
			g[i + 1].push_back(i);
			is[i] = true;
		}
	is[n] = true;
	dfs(n, 0);
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
