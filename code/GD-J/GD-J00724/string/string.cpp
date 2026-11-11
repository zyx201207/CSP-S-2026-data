#include<bits/stdc++.h>
using namespace std;

long long n, a[200005];
char c[200005];
string s;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (long long i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	
	long long l = 1, r = n, ans = 0;
	while (l <= r) {
		if (a[l] > a[r]) {
			if (c[l] != c[r]) ans += a[r];
			a[l] -= a[r];
			--r;
		} else if (a[r] > a[l]) {
			if (c[l] != c[r]) ans += a[l];
			a[r] -= a[l];
			++l;
		} else {
			if (c[l] != c[r]) ans += a[l];
			--r, ++l;
		}
	}
	cout << ans << endl;
	return 0;
} 
