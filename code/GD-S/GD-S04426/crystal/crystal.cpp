#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long n, m, a[N], s[N];

bool check (int mid) {
	for (long long i = 1; i <= n - mid + 1; i ++)
		if (s[i + mid - 1] - s[i - 1] + m >= mid * a[i + mid - 1]) return true;
	return false;
}

int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i ++) cin >> a[i];
	sort (a + 1, a + n + 1);
	for (long long i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
	long long l = 1, r = n, ans = 1;
	while (l < r) {
		long long mid = (l + r + 1) / 2;
		if (check (mid) == true) l = mid, ans = l;
		else r = mid - 1;
	}
	cout << ans << "\n";
	return 0;
}
