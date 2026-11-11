#include <bits/stdc++.h>
using namespace std;

int n, a[200010];
string c[200010];
long long ans, p;

int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		p += 1LL * a[i];
	}
	int l = 1, r = n;
	long long L = 0, R = p + 1;
	while (L + 1 < R) {
		if (l < r) {
			L += 1LL * min(a[l], a[r]), R -= 1LL * min(a[l], a[r]);
			if (c[l] != c[r]) {
				ans += 1LL * min(a[l], a[r]);
			}
			//---------------
			if (a[r] == a[l]) {
				l++, r--;
			}
			if (a[l] > a[r]) {
				r--;
				a[l] -= a[r];
			}
			if (a[r] > a[l]) {
				l++;
				a[r] -= a[l];
			}
		}
		else break;
	}
	cout << ans << endl;
}
