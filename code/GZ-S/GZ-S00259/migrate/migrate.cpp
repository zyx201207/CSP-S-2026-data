//GZ-S00259, 孟杰锐， 贵阳市第一实验中学
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int c, T;
int n, m;
int a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
		
	cin >> c >> T;
	
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		
		for (int i = 1; i <= n; i++) {
			if ((a[n] - a[1]) % m == 0) {
				cout << (a[n] - a[1]) / m;
				continue;
			}
		}
	}
	
	
	return 0;
} 
