#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m, a[N], sum[N], ans;
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (long long i = n - 1; i >= 1; i--) {
		sum[i] = sum[i + 1] + a[i] - a[i - 1];
	}
	long long i = n - 1;
	while (1) {
		ans++;
		if (sum[i] > m) {
			break; 
		}
		m = m - sum[i];
		i--;
	}
	cout << ans;
	return 0;
}
