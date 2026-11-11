//#include <bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 10;
//int n, m;
//int a[N];
//int ans = -1;
//void dfs(int cur, int cnt, int sum) {
//	if (cnt > m) return ans = max(ans, sum), void();
//	for (int i=cur+1; i<=n-(m-cnt)+1; i++) {
//		if (sum == 0) dfs(i, cnt+1, a[i]);
//		else dfs(i, cnt+1, sum & a[i]);
//	}
//}
//int main() {
//	freopen("and2.in", "r", stdin);
//	cin >> n >> m;
//	for (int i=1; i<=n; i++) cin >> a[i];
//	dfs(0, 0, 0);
//	cout << ans;
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int n, m;
int a[N];
long long dp[N][N]; // ǰiѡj 
int main() {
	freopen("and3.in", "r", stdin);
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) dp[i][1] = a[i];
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] & a[i]);
		}
	cout << dp[n][m];
	return 0;
}

