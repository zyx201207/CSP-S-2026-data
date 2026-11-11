#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n, m, a[N], s[N];
signed main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i-1] + a[i];
	}
	int ans = 0;
	for (int i = n, j = n; i >= 1; i--) {
		while (j > 1 && (j > i || a[i] * (i - j + 2) - (s[i] - s[j-2]) <= m)) {
			j--;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}
