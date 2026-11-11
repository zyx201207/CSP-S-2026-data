#include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;
long long a[N];
long long c, t, n, d;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --) {
		cin >> n >> d;
		long long ch = 0;
		for(long long i = 1; i <= n; i ++) {
			cin >> a[i];
			ch = a[i] - a[i-1];
		}
		if(ch <= d) cout << (n % 2 == 0 ? n / 4 : n / 2) << endl;
		else cout << 0 << endl;
	}
	return 0;
}
