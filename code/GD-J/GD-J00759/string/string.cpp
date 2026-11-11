#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, a[N], l, r, l1, r1, res, ans, k;
string s[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	l = 1, r = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
		res += a[i];
	}
	while (l <= r) {
		k = min(a[l] - l1, a[r] - r1);
		if (s[l] != s[r]) ans += k;
		l1 += k, r1 += k;
		if (l1 == a[l]) l++, l1 = 0;
		if (r1 == a[r]) r--, r1 = 0;
	}
	cout << ans << '\n';
	return 0;
}
