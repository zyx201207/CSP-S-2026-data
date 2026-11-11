#include <bits/stdc++.h>
using namespace std;
//地铁双向通行 
//c:25 n:500 m,k:5e5 d:2 q:1e5 
const int N = 5e5 + 5;
int c, n, m, d, q;
long long w[N], a[105][N], t[105][N], mp[N][105];
vector<int> vt[105], had[N];
bool vis[N];
long long ans = 1e18;
void dfs(int x, int goal, long long sum) {
	if (goal == x) {
		ans = min(ans, sum);
		return ;
	}
	for (int i = 0; i < had[x].size(); i++) {
		int id = had[x][i];
		for (int j = 0; j < vt[id].size(); j++) {
			int to = vt[id][j];
			if (to == x || vis[to]) continue ;
			vis[to] = 1;
			dfs(to, goal, sum + mp[x][id] + mp[to][id]);
			vis[to] = 0;
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
			had[a[i][j]].push_back(i);
			mp[a[i][j]][i] = t[i][j];
			vt[i].push_back(a[i][j]);
		}
	}
	while (q--) {
		int xr, yr;
		cin >> xr >> yr;
		ans = 1e18;
		dfs(xr, yr, 0);
		cout << ans + w[xr] + w[yr] << '\n';
	}
	return 0;
}
