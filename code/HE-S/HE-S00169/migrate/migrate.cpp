#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e6 + 10;
long long c, t;
long long n, d;
long long a[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		long long cnt = 0;
		for (int i = 1; i <= n - 2; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (abs(a[i] - a[i]) <= d * 2 && j - i >= 2) {
					cnt++;
				}
			}
		}
		cout << cnt / 3 << endl;
	}
	return 0;
}
