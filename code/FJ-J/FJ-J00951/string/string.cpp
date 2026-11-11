#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[200005], sum, ans;
char c[200005];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	int l = 1, r = sum, xl = 1, xr = n;
	while (l <= r) {
		int tmp = min(a[xl], a[xr]);
		if (c[xl] != c[xr]) ans += tmp;
		l += tmp;
		r -= tmp;
		if (tmp == a[xl]) xl++;
		else a[xl] -= tmp;
		if (tmp == a[xr]) xr--;
		else a[xr] -= tmp;
	}
	cout << ans;
	return 0;
}
