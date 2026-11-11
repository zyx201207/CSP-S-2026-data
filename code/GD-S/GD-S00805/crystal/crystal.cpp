#include<bits/stdc++.h>
using namespace std;

long long n, a[500005], m;
long long cha[500005];
long long sum[500005];

signed main() {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + 1 + n);
	for (long long i = 1; i <= n; i++) {
		cha[i] = a[n] - a[i];
	}
	for (long long i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + cha[i];
//		cout << i << " :" << sum[i] << endl;
	}
	long long ans = 0, l = 1, r = 1;
	while (l <= n) {
		long long cnt = 1;
		while (r + 1 <= n && sum[r + 1] - sum[l - 1] - (r + 1 - l + 1) * (a[n] - a[r + 1]) <= m) {
			++r;
		}
		ans = max(ans, r - l + 1);
		++l;
	}
	cout << ans << endl;
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/
