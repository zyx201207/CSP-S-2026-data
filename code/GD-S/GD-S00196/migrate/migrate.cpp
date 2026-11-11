#include<bits/stdc++.h>
using namespace std;
#define PII pair<int, int>

const int N = 500100, K = 600;

int test, T;
long long a[N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> test >> T;
	while (T--) {
		long long n, d;
		cin >> n >> d;
		bool A = true;
		long long Adiff = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i == 2)
				Adiff = a[i] - a[i - 1];
			if (a[i] - a[i - 1] != Adiff && i != 1)
				A = false;
		}
		if (A) {
			if (d < 3 * Adiff <= 2 * d && d >= 2 * Adiff) {
				if (n - 3 <= 0)
					cout << 0 << endl;
				else
					cout << n - 3 << endl;
			}
			else
				cout << 0 << endl;
		}
//		if (n <= 30) {
//			for (int i = 1; i <= n; i++) {
//				for (int j = i + 3; j <= n; j++) {
//					if (a[j] - a[i] <= d)
//						continue;
//					for (int k = i + 1; k < j; k++) {
//						if (a[k] - a[i] <= d)
//					}
//				}
//			}
//		}
		cout << 0 << endl;
	}
	return 0;
}
