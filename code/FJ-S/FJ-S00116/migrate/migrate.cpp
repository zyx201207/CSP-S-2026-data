#include <bits/stdc++.h>
using namespace std;
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	
	for (int i = 1; i <= t; ++i) {
		int n, m;
		cin >> n >> m;
		
		for (int i = 1, a; i <= n; ++i)
			cin >> a;
		
		if (n % m == 0)
			cout << "1\n";
		else
			cout << "0\n";
	}
	
	return 0;
}
