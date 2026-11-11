#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 10;

int c, T;
int n, d;
int pos[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> T;
	
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> pos[i];
		}
		if (n == 1 || n == 2 || n == 3) {
			cout << 0 << endl;
			continue;
		}
		cout << (n * (n - 1) >> 1) << endl;
	}
	
	return 0;
}
