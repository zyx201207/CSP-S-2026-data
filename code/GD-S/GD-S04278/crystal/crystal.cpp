#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;

int ans = 0;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a.begin() + 1, a.begin() + n + 1);
	vector <int> dp(n + 1, 0);
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
	
	int prev = 1, pred = 0;
	for (int i = 1; i <= n; i++) {
		pred += (prev - 1) * (a[i] - a[i - 1]);
		int now = dp[i] - pred;
				
		int p = prev;
		for (int j = p; j < i; j++) {
			prev = j;
			if (now <= m) break;
			
			pred += a[i] - a[j];
			now -= a[i] - a[j];
		}
		
		int res = i - prev + 1;
		ans = max(ans, res);
	}
	
	cout << ans << '\n';
	
	return 0;
}
