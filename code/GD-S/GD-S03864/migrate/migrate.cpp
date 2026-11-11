#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
const int _N = N + 5;
ll x[_N], dp[_N][_N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int C, T; cin >> C >> T;
	while(T--) {
		ll n, d; cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		int ans = 0;
		for(int u = 1; u <= n - 1; u++) {
			for(int v = u + 1; v <= n; v++) {
				if(x[v] - x[u] <= d) dp[u][v] = 1;
				else dp[u][v] = 0;
				for(int t = u + 1; t < v; t++) {
					dp[u][v] += dp[u][t] * dp[t][v];
				} if(dp[u][v] == 2) ans++;
			} 
		} cout << ans << endl;
	}
	return 0;
} 
