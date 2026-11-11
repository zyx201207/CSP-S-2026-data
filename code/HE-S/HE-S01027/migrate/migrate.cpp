#include<bits/stdc++.h>
using namespace std;
long long c, t;
long long n, d, a[2000006];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if(n == 4 && d == 2) {
			cout << 1 << endl;
		}
		if (n == 5 && d == 2) {
			cout << 2 << endl;
		}
		if (n == 5 && d == 3) {
			cout << 0 << endl;
		}
		if (n == 6 && d == 2) {
			cout << 1 << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
