#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5 * 1e5 + 5;
int n, m, a[N], ans, cnt;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int sum = 0, aver = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum += a[i];
	}
	aver = sum / n; 
	for (int i = 1; i <= n; i ++) {
		a[i] = abs(aver - a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		if (cnt + a[i] <= m) {
			cnt += a[i];
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
