#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[200200], dp[2020][2020]; 
signed main() {
	freopen("and.in" , "r", stdin );
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		int mx = -1;
		for (int i = 1; i <= n; i++) {
			mx = max(mx, a[i]);
		}
		cout << mx;
		return 0;
	} 
	if (m == 2) {
		int mmx = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				mmx = max(mmx, a[i] & a[j]);
			}
		}
		cout << mmx;
		return 0;
	}
	if (m == n) {
		int sum = a[1];
		for (int i = 2; i <= n; i++) {
			sum &= a[i];
		}
		cout << sum;
		return 0;
	}
	sort(a + 1, a + n + 1);
	int ans = a[n];
	for (int i = n - 1; i >= n - m + 1; i--) {
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
/*
3  0011
15 1111
&  0011 = 3
FUCK
awa
qaq
*/
