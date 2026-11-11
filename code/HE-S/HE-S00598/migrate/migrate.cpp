#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5010, aN = 2e6 + 10;
bool st[N][N];
ll x[aN];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t --) {
		int n;
		ll d;
		cin >> n >> d;
		bool flag = true;
		for (int i = 1; i <= n; i ++) cin >> x[i];
		ll cz = x[2] - x[1];
		for (int i = 1; i <= n; i ++) 
			if (i != 1 && x[i] - x[i - 1] != cz) flag = false;
		if (flag) {
			ll op = n - 1, mx = 0;
			for (int i = 1; i < n; i ++) {
				mx += cz;
				if (mx > d) {
					op = i - 1;
					break;
				}
			}
			if (op <= 1) cout << 0 << "\n";
			else if (op == 2) cout << n - 3 << "\n";
			else if (op == 3) cout << n - 5 << "\n";
			else {
				if (op % 2) cout << 0 << "\n";
				else cout << op + 3 << "\n";
			}
			continue;
		}
	}
	return 0;
}
