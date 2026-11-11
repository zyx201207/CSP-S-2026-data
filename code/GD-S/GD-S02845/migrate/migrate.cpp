#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, a[2000005]; 
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --) {
		cin >> n >> d;
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i ++) cin >> a[i];
		int sum = 0;
		bool flag = 0;
		for(int i = 3; i <= n; i ++) if(abs(a[i] - a[i - 1]) != abs(a[i - 1] - a[i - 2])) flag = 1;
		cout << (flag == 1 ? ((n - 1) * (n - 2) / 2) : (n - d - 1)) << '\n';
	}
	return 0;
}
