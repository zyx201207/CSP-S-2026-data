#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m, ans = 0;
	cin >> n >> m;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	ans = a[n - 1];
	for (int i = n - 2; i >= n - m; i--) {
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}
