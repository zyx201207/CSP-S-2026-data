#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, n, d, x[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		cin >> x[0];
		bool flag = 1;
		int len = 0;
		for (int i = 1; i < n; ++i) {
			cin >> x[i];
			if (x[i] - x[i - 1] > d) {
				if (i <= 3) flag = 0;
			} else {
				len++;
			}
		}
		if (!flag)
			cout << 0;
		else if (d >= len && x[len] - x[len - 1] <= d)
			cout << 0;
		else
			cout << len - 2;
		cout << "\n";
	}
	return 0;
}