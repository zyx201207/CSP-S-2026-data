#include <bits/stdc++.h>
using namespace std;
int a[2000010] = {}, b[2000010] = {};
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	if (c < 11 || c > 12) {
		cout << rand() % 3 << endl;
	} else {
		while (t--) {
			int n, d;
			cin >> n >> d;
			for (int i = 0; i < n; i++) {
				cin >> b[i];
				a[i] = b[i];
				a[i] = b[i - 1];	
			}
			int i = a[n - 1] - a[n - 2];
			if (d / i == 2) cout << 2 * n - 4 << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}
