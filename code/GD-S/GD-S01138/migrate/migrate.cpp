#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define endl '\n'

using namespace std;

const int N = 2e6 + 5;
int n, d, a[N], ans = 0;

void solvea() {
	if (d <= a[2] - a[1]) cout << 0 << endl;
	else if (d >= (a[2] - a[1]) * 2) {
		cout << n - 3 << endl;
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, _;
	cin >> c >> _;
	while (_--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (c >= 11 && c <= 12) solvea();
		else if (c >= 13 && c <= 14) {
			
		}
	}
	return 0;
}
