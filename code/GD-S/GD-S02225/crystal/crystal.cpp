#include <bits/stdc++.h>
using namespace std;


long long n, m;
long long a[500010];
long long s[500010];
long long l, r, mid, ans;
long long t, t1, t2, ts;
bool check(long long x) {
//	printf("x:%lld\n", x);
	for (int l = 1; l + x - 1 <= n; l++) {
		if (a[l + x - 1] * (x - 1) - (s[l + x - 2] - s[l - 1]) <= m) {
			return true;
		}
	}
	return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	ans = 1;
	l = 2, r = n;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
6 3
-9 -2 0 1 3 7
*/

