#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

long long a[N], dp[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	long long ans = 0;
	for(int k = 1; k <= n; k ++) {
		dp[1] = a[k];
		for(int i = 1; i <= n; i ++) {
			for(int j = m; j >= 1; j --) {
				dp[j] = max(a[j], dp[j-1] & a[i]);
			}
		}
		ans = max(ans, dp[m]);
		memset(dp, 0, sizeof(dp));
	}
	cout << ans << endl;
	return 0;
}
