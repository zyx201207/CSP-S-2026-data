#include<bits/stdc++.h>
using namespace std;

long long c, t;
long long n, d;
long long x[2000010];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		long long w = x[2] - x[1];
		long long v = d / w;
		if (v < 2) {cout << 0 << '\n';continue; 
		}
		cout << max(0LL, n - 2 * v + 1) << '\n';\
	}
	return 0;
}
