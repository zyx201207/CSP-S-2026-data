#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
LL n, a[N], sum, m;
char b[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i] >> b[i];
		sum += a[i];
	}
	sum /= 2;
	LL cnt1 = 0, cnt2 = 0, ans = 0;
	LL l = 1, r = n;
	while (l <= r) {
		if (l == r || cnt1 > sum || cnt2 > sum) break;
		if (a[l] > a[r]) {
			if (b[l] != b[r]) ans += a[r];
			a[l] -= a[r];
			cnt2 += a[r];
			r -- ;
		} else if (a[r] > a[l]) {
			if (b[l] != b[r]) ans += a[l];
			a[r] -= a[l];
			cnt1 += a[l];
			l ++ ;
		} else if (a[r] == a[l]) {
			if (b[r] != b[l]) ans += a[l];
			cnt1 += a[l];
			cnt2 += a[r];
			l ++ , r -- ;
		}
	}
	cout << ans << '\n';
	return 0;
}
