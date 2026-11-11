#include <bits/stdc++.h>
#define int long long
#define qwq return
using namespace std;
int x[2000007];

inline void sol () {
	int n, d; cin >> n >> d;
	if (n <= 3 || d == 1) {
		cout << "0\n";
		qwq;
	}
	for (int i = 1; i <= n; i ++)
		cin >> x[i];
	sort(x + 1, x + n + 1);
	int diff = x[n] - x[n - 1];
	if (diff * 2 == d) cout << n - d - 1 << "\n";
	else cout << "0\n";
	qwq;
}

int32_t main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	int c, T;
	cin >> c >> T;
	while (T --)
		sol();
	qwq 0;
}
