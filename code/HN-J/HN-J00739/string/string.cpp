#include <bits/stdc++.h>
#define int long long
using namespace std;

struct str {
	int l;
	char s;
} a[200005];

int n, ans;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].l >> a[i].s;
		a[i].l += a[i - 1].	l;
	}
	int l = 1, r = n, xl = 0;
	for (; l < r; ) {
		int ldis = a[l].l - xl;
		int rdis = a[n].l - xl - a[r - 1].l;
		if (ldis < rdis) {
			if (a[l].s != a[r].s) ans += ldis;
			xl = a[l].l, l++;
		} else if (ldis == rdis) {
			if (a[l].s != a[r].s) ans += ldis;
			xl = a[l].l, l++, r--;
		} else {
			if (a[l].s != a[r].s) ans += rdis;
			xl = a[n].l	- a[r - 1].l, r--;
		}
	}
	cout << ans << '\n';
	return 0;
}
