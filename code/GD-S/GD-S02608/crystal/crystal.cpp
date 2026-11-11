#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5e5 + 10;

ll n, m, a[N], pre[N], dp[N], ans = 1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	ll l = 1, sum = 0;
	for (int r = 2; r <= n; r++) {
		sum = r - l + 1;
		if (a[r] * sum - pre[r] + pre[l - 1] <= m) 
			ans = max(ans, sum);
		else l++;
	}
	cout << ans << '\n';
	return 0;
} 
