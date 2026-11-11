#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e4 + 10;//2e5 + 10
int n, m, a[(int) 2e5 + 10];
int dp[MAX][MAX];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	sort(a + 1, a + n + 1);
	
	for(int i = 1; i <= n; i++) {
		dp[i][1] = a[i];
		for(int j = 2; j <= m; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			dp[i][j] = max(dp[i][j], (dp[i - 1][j - 1] & a[i]));
		}
	}
	
	printf("%d", dp[n][m]);
	return 0;
}
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/


