#define ffopen(s) \
cin.tie(0)->sync_with_stdio(0); \
freopen(#s ".in", "r", stdin); \
freopen(#s ".out", "w", stdout); \
//
#include <bits/stdc++.h>
using namespace std;
using intl = long long;
const int N = 500000;
int n;
intl m, a[N + 10], b[N + 10];
int main() { ffopen(crystal);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i];
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l < r) {
			int j = (l + r) >> 1;
			if ((i - j) * a[i] - (b[i - 1] - b[j - 1]) <= m) r = j;
			else l = j + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << '\n';
	return 0;
}
