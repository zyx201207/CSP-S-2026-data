#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, a[N], ans;
char c[N];
signed main() {
	freopen("string.in", "r", stdin), freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i] >> c[i];
	int i = 1, j = n;
	while (i < j) {
		if (a[i] > a[j]) {
			if (c[i] != c[j]) ans += a[j];
			a[i] -= a[j], a[j] = 0;
		} else {
			if (c[i] != c[j]) ans += a[i];
			a[j] -= a[i], a[i] = 0;
		}
		if (!a[i]) ++i;
		if (!a[j]) --j;
	}
	cout << ans;
	return 0;
}
