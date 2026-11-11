#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 10;
vector<int> edge[N];
int dp[N];
int dfs(int u) {
	if (u == 1) return 1;
	if (dp[u]) return dp[u];
	for (int v : edge[u]) {
		dp[u] += dp[v] = dfs(v);
	}
	return 0;
}

signed main() {
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	
	while (t--) {
		int n, d;
		cin >> n >> d;
		vector<int> x(n + 1);
		
 		for (int i = 1; i <= n; i++) {
 			cin >> x[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] <= d) {
					edge[j].push_back(i);
				}
			}
		}
		for (int i = n; i > 0; i--) {
			dfs(i);
			int ans = 0;
			for (int j = 1; j <= n; j++) {
				ans += (dp[j] == 2);
				dp[j] = 0;
			}
			cout << ans << '\n'; 
		}
	}
	
	return 0;
}
