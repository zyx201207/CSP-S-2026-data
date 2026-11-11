#include <bits/stdc++.h>

using namespace std;

unsigned long long c, t, n, d;
unsigned long long x[2000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t --) {
		cin >> n >> d;
		for (int i = 0; i < n; i ++) {
			cin >> x[i];
		}
		unsigned long long k = x[1] - x[0];
		if (k > d) {
			cout << 0 << endl;
			continue ;
		}
		if (x[2] - x[0] < d) {
			cout << (x[n - 1] - x[0]) / k - 2 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}
