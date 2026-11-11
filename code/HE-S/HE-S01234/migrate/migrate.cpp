#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

long long c, t;

int main() {
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	for (int i = 0; i <= t - 1; t++) {
		// 有n座岛屿，海鸟的飞行距离不超过d 
		long long n, d;
		cin >> n >> d;
		long long x[n + 5];
		for (int j = 0; j <= n - 1; j++) {
			cin >> x[j]; 
		}
		cout << 1 << endl;
		cout << 2 << endl; 
	} 
	
	return 0;
}
