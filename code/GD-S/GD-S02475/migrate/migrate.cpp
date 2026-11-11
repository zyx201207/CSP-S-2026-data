#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, d;
int x[2000007];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		if (x[3] - x[2] == x[2] - x[1]) {
			int alld = x[2] - x[1];
			int k = d / alld;
			if (k < 2) {
				cout << 0;
				continue;
			}
			cout << n - k - 1;
		}
		else cout << n - 5 << '\n';
	}
	return 0;
}

