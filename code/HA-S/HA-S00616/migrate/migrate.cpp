#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2000010;
int c, t, n, d, x[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		if (n == 1) cout << "0\n";
		else if (d <= x[2] - x[1]) cout << "0\n";
		else cout << max(0LL, n - d / (x[2] - x[1]) * 2 + 1) << "\n";
	}
	return 0;
}
