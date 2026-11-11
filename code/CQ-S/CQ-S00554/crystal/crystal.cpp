#include <bits/stdc++.h>

using namespace std;
const int N = 5e5;
int n, l, ans;
long long m, a[N + 5];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long sum = a[2] - a[1];
	ans = 1;
	for(int i = 2; i <= n; i ++) {
		while(sum > m) {
			sum -= a[i] - a[++ l];
		}
		ans = max(ans, i - l);
		sum += (a[i + 1] - a[i]) * (i - l);
	}
	cout << ans << '\n';
	return 0;
}
