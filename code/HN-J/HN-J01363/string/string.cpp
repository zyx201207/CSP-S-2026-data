#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 2e5 + 10;

int a[kMaxN], n, ans;
char c[kMaxN];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	for (int i = 1, j = n; i < j;) {
		if (a[i] == a[j]) {
			ans += a[i] * (c[i] != c[j]);
			i++, j--;
		} else if (a[i] < a[j]) {
			ans += a[i] * (c[i] != c[j]);
			a[j] -= a[i], i++;
		} else {
			ans += a[j] * (c[i] != c[j]);
			a[i] -= a[j], j--;
		}
	}
	cout << ans << '\n';
  return 0;
}
