#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N];
void solve() {
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int tmp = m;
		int cnt = 0;
		for (int j = 1; a[j] <= a[i]; j++) {
			int diff = a[i] - a[j];
			if (tmp - diff >= 0) {
				cnt++;
				tmp -= diff;
			} else {
				break;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
}
void solve2() {
	int sum = 0;
	int diff = a[2] - a[1];
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		sum += (i - 1) * diff;
		if (m >= sum) {
			ans = max(ans, i);
		} else {
			break;
		}
	}
	cout << ans << '\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	bool f = 1;
	for (int i = 2; i < n; i++) {
		if (a[i] - a[i - 1] != a[i + 1] - a[i]) {
			f = 0;
			break;
		}
	}
	if (f == 1) {
		solve2();
		return 0;
	}
	solve();
	return 0;
} 
