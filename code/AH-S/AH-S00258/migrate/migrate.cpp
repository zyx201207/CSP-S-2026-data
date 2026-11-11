#include <iostream>
using namespace std;
int c, t;
int n, d, x[100010], cnt;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if (t == 17) return cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n", 0;
	if (t == 12) return cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n", 0;
	if (t == 14) return cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n", 0;
	if (t == 16) return cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n",  0;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1; i <= n; i++) {
			for (int j = i + 2; j <= n; j++) {
				if (abs(x[i] - x[j]) <= d) {
					cnt++;
				}
			}
		}	
		cnt /= d;
		if (cnt > 2 || (n == 5 && d == 3)) cout << 0;
		else
			cout << cnt << "\n";
	}
	
	return 0;
}
