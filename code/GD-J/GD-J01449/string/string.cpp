#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N];
char b[N];
long long res;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
	int l = 1, r = n;
	while (l < r) {
		int t = min(a[l], a[r]);
		if (b[l] != b[r]) res += t;
		a[l] -= t, a[r] -= t;
		if (!a[l]) ++l;
		if (!a[r]) --r;
	}
	cout << res << '\n';
	return 0;
}
