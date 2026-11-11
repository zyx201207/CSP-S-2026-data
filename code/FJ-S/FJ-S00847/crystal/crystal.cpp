#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

long long n, m;
long long a[N], sum[N];

bool check (long long x) {
	for (int i = n; i >= x; i--)
		if (a[i] * x - (sum[i] - sum[i - x]) <= m) return 1;
	return 0; 
}

int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	sort (a + 1, a + 1 + n);
//	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
//	for (int i = 1; i <= n; i++) cout << sum[i] << ' ';
	
	int l = 1, r = n, ans = 1;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	
	cout << ans;
	return 0;
}
