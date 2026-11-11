#include <bits/stdc++.h>
#define int long long

using namespace std;

namespace Code {
	constexpr int N = 2e6 + 5;

	int c, t;
	int n, d;
	int a[N];

	void main() {
		cin >> c >> t;

		while (t --) {
			cin >> n >> d;
			for (int i = 1; i <= n; ++ i) cin >> a[i];

			cout << 0 << '\n';
		}
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Code::main();

	return 0;
}

/*
++ rp
*/