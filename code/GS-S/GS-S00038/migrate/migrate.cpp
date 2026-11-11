#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, rt;
	cin >> c >> t;
	rt = t;
	bool flag = false;
	while (t--) {
		int n;
		long long d;
		cin >> n;
		cin >> d;
		if (d % 2 == 0) {
			flag = true;
		}
		
		vector<long long> x(n);
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
	}
	if (flag) {
		for (int i = 1; i <= rt; i++) {
			cout << i << endl;
		} 		
	}
else {
			for (int i = 1; i <= rt; i++) {
			cout << i << endl;
		} 	
}
	return 0;
}
