#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n;
ll m, a[N], sum[N];
bool check(int x) {
	for (int i = x; i <= n; i++) {
		ll now = a[i] * x - (sum[i] - sum[i - x]);
		if (now <= m) return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int l = 0, r = n, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}