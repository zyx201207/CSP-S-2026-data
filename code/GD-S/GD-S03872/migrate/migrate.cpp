#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5;
int c, t, n, d, ans, a[N], dis[N], sum[N], dp[N];
void solve1() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++)  cin >> a[i];
	for(int l = 1, r, x; l <= n - 1; l++) {
		x = l, r = l + 1;
		while(r <= n) {
			while(a[r] - a[x] > d)  x++;
			if(x == r)  break;
			dis[r] = dis[x] + 1;
			r++;
		}
		for(int i = 1; i <= n; i++)  sum[i] = 0;
		x = l, r--, sum[0] = dp[l] = 1;
		for(int k = l + 1; k <= r; k++) {
			while(a[k] - a[x] > d) {
				sum[dis[x]] -= dp[x];
				x++;
			}
			dp[k] = sum[dis[k] - 1];
			if(dp[k] == 2)  ans++;
			else if(dp[k] > 2)  break;
			sum[dis[k]] += dp[k];
		}
	}
	cout << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--) {
		if(c <= 10)  solve1();
	}
	return 0;
}
