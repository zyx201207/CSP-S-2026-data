#include <bits/stdc++.h>

using namespace std;

const int MaxM = 200007;
long long dp[2][MaxM];
long long n, m;
long long a[MaxM];
int rip = 0;

void nl() {
	rip ++;
	rip %= 2;
	
	memset(dp[rip], 0, sizeof(dp[rip]));
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i ++) {
		dp[rip][i] = a[i];
	}
	
	for (int i = 2; i <= m; i ++) {
		nl();
		for (int j = 0; j < n; j ++) {
			dp[rip][j] = max(dp[(rip ^ 1)][j] & a[j], dp[rip][j]);
		}
	}
	
	
	int ans = 0;
	for (int j = 0; j < n; j ++) {
		if (dp[rip][j] > ans) {
			ans = dp[rip][j];
		}
	}
	
	cout << ans;
	
	return 0;
}
