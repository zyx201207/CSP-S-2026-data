#include <bits/stdc++.h>
using namespace std;
int n, a[200010];
long long sz, ans;
char c[200010];
int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
		sz += a[i];
	} 
	long long l = 1, r = n;
	while (l <= r) {
		if (c[l] == c[r]) {
			if (a[l] < a[r]) {
				a[r] -= a[l], l ++;
			}
			else if (a[l] > a[r]) {
				a[l] -= a[r], r --;
			}
			else {
				if (l == r) break;
				else l ++, r --;
			}
		} else {
			if (a[l] < a[r]) {
				ans += a[l];
				a[r] -= a[l];
				l ++;
			} else if (a[l] > a[r]) {
				ans += a[r];
				a[l] -= a[r];
				r --;
			} else {
				ans += a[l];
				l ++, r --;
			}
		}
	}
	cout << ans;
	return 0;
}
//100pts
