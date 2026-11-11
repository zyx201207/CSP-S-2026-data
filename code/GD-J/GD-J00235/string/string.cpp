#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i] >> c[i];
	}
	int l = 1,ll = a[l],r = n,rr = a[r];
	long long ans = 0;
	while (l < r) {
		if (c[l] == c[r]) {
			l++;
			ll = a[l];
			r--;
			rr = a[r];
		} else {
			if (ll > rr) {
				ans += rr;
				ll -= rr;
				r--;
				rr = a[r];
			} else if (ll < rr) {
				ans += ll;
				rr -= ll;
				l++;
				ll = a[l];
			} else {
				l++;
				ll = a[l];
				r--;
				rr = a[r];
				ans += ll;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

