#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	map<pair<int, int>, int> dp;
	for (int i = 0; i < n; i++) for (int j = 1; j <= m; j++) dp[{i, j}] = INT_MAX;
	for (auto &x : a) cin >> x;
	dp[{0, 1}] = a[0];
	for (int i = 1; i < n; i++) {
		dp[{i, 1}] = a[i];
		for (int j = 2; j <= m && j < i + 2; j++) {
			for (int k = 1; k < i; k++) 
				if (dp[{i - k, j}] == INT_MAX) dp[{i, j}] = dp[{i - k, j - 1}] & a[i];
				else dp[{i, j}] = max(dp[{i - k, j}], dp[{i - k, j - 1}] & a[i]);
		}
	} int ans = INT_MIN;
	cout << dp[{n - 1, m}];
}

