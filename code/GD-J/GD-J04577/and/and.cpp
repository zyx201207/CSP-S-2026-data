#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	vector<ull> a(n + 1);
	vector<ull> dp(n + 1);
	ull maxValue = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxValue = max(maxValue, a[i]);
		dp[i] = a[i];
	}

	if (m == 1) {
		cout << maxValue << '\n';
		return 0;
	}
	
	ull ans = 0;
	for (int i = 2; i <= m; i++) {
		for (int j = n; j >= i; j--) {
			dp[i] = 0;
			for (int k = i - 1; k < j; k++)
				dp[i] = max(dp[i], dp[k] & a[j]);
			if (i == m) ans = max(ans, dp[i]); 
		}
	} 
	
	cout << ans << '\n';
	
	return 0;
}
