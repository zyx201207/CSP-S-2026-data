#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
long long c, t, n, d, ans, a[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t --) {
		cin >> n >> d;
		ans = 0;
		for (int i = 1;i <= n;i ++) cin >> a[i];
		int gong = a[2] - a[1];
		int r = a[1] + d + gong;
		ans += n - r + 1;
		cout << ans << "\n";
	}
	return 0;
}

