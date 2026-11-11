#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int id, t;
int n;
long long d;
long long x[N];
int vis[N];
vector<int>e[N];
int dep[N], dp[N], ad[N];
int fa[N];
long long ans = 0;
void dfs(int u, long long y) {
	dep[u] = dep[fa[u]] + 1;
	if(vis[u]) dp[u] = dep[u];
	long long res = 0;
	for(int v : e[u]) {
		if(v == fa[u]) continue;
		if(vis[u]) y = 0;
		fa[v] = u;
		dfs(v, y + u - v - ad[v] + 1);
		dp[u] = min(dp[u], dp[v]);
		res += (dep[u] - dp[v]);
//		cout << dep[u] << " " << dp[v] << "\n";
	}
//	cout << u <<" " << vis[u] << " " << res << " " << y << "\n";
	if(vis[u] == 1) {
		ans += res * y;
	} else {
		ans += res * ad[u];
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> id >> t;
	while(t--) {
		cin >> n; cin >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		ans = 0;
		for(int i = 1; i <= n; i++) e[i].clear();
		for(int i = n; i >= 1; i--) {
			int k = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
			if(k > i) e[k].push_back(i);
//			cout << k << " " << i << "\n";
			if(i >= 2 && x[i - 1] + d >= x[k] && k > i) {
				vis[i]++;
				if(i >= 3 && x[i - 2] + d >= x[k] && k > i) {
					vis[i]++;
				}
			}
			int r = upper_bound(x + 1, x + n + 1, x[i - 1] + d) - x - 1;
			int l = i + 1;
			if(i > 1) ad[i] = max(0, r - l + 1);
//			cout << i << " " << k << " " << l << " " << r << "\n";
		}
		dfs(n, 0);
		cout << ans << "\n";
	}
	return 0;
} 
/*
若想转战与t为同一个点，当前线路并非最优 

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
