#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N], b[N], c[N];
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n, m, m1;
	long long T = 0; 
	cin >> n >> m;
	m1 = m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n % 2 == 1) {
		long long ans = 0;
		for (long long i = 1; i <= n; i++) {
			b[i] = llabs(a[n / 2 + 1] - a[i]);
		}
		sort(b + 1, b + n + 1);
		for (long long i = 1; i <= n; i++) {
			if (m - b[i] >= 0) {
				ans++;
				m -= b[i];
			}
			else {
				break;
			}
		}
		cout << ans;
	}
	else {
		long long ans1 = 0;
		for (long long i = 1; i <= n; i++) {
			b[i] = llabs(a[n / 2] - a[i]);
		}
		sort(b + 1, b + n + 1);
		for (long long i = 1; i <= n; i++) {
			if (m - b[i] >= 0) {
				ans1++;
				m -= b[i];
			}
			else {
				break;
			}
		}
		long long ans2 = 0;
		for (long long i = 1; i <= n; i++) {
			c[i] = llabs(a[n / 2 + 1] - a[i]);
		}
		sort(c + 1, c + n + 1);
		for (long long i = 1; i <= n; i++) {
			if (m1 - c[i] >= 0) {
				ans2++;
				m1 -= c[i];
			}
			else {
				break;
			}
		}
		cout << max(ans1, ans2);
	}
	return 0;
}
