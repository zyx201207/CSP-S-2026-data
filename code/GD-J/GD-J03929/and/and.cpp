#include <bits/stdc++.h>
#define inc(i, l, r) for(long long i = l; i <= r; ++i)
#define dec(i, l, r) for(long long i = l; i >= r; --i)
using namespace std;

const int N = 2 * 1e3 + 5;

long long n, m, a[N], dp[N][N], ans = 0;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	inc(i, 1, n) cin >> a[i];
	memset(dp, -1, sizeof dp);
	dp[1][1] = a[1];
	inc(i, 1, n) {
		for(int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j];
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] & a[i]);
		}
	}
	inc(i, 1, n) {
		ans = max(ans, dp[i][m]);
	}
	cout << ans << '\n';
	return 0;
} 
