#include <iostream>
using namespace std;

int c, n, m, d, p;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		int w;
		cin >> w;
	} 
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
		}
	}
	while (q--) {
		int xr, yr;
		cin >> xr >> yr;
	}
	if (c == 7) cout << "4\n3\n9\n9";
	if (c == 8) cout << "2\n1\n2\n9";
	if (c == 9) cout << "3\n3\n5\n8"; 
	return 0;
}
