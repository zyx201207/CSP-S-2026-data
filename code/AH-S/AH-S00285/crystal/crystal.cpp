#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N], d[N];
long long n, m;
bool check (long long mid) {
	for (int i = 1; i <= n - mid + 1; i++) {
		int r = i + mid - 1;
		if (mid * a[r] - d[r] + d[i - 1] <= m) return 1;
	} return 0;
} long long fun () {
	long long l = 1, r = n, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check (mid)) l = mid + 1;
		else r = mid - 1;
	} return l - 1;
} int main() {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	} sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) d[i] = d[i - 1] + a[i];
	cout << fun ();
	return 0;
}
