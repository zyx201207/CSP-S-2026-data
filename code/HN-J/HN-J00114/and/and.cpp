#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int n, m;
long long a[N];
long long dp[N][N]; // ǰiѡj-Max 
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> a[i];
	if (n > N) {
		sort(a + 1, a + 1 + n);
		cout << a[m];
	} else {
		for (int i=1; i<=n; i++) dp[i][1] = max(dp[i - 1][1], a[i]);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] & a[i]);
			}
		cout << dp[n][m];		
	}
	return 0;
}
