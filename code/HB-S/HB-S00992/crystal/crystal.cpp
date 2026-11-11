#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;
int n;
long long m, ans = -1e18;
long long a[MAXN];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	// so we need to sort first
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		long long cost = 0;
		for (int j = i; j >= 1; --j) {
			if (cost + a[i] - a[j] <= m) {
				cost += a[i] - a[j];
			}
			else {
				ans = max(ans, (long long)i - j);
				break;
			}
			if (j == 1) {
				ans = max(ans, (long long)i);
			}
		}
	}
	cout << ans;
	return 0;
}
