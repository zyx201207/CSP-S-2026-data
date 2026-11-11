#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
int n;
ll m, a[N], pre[N];
bool check(int len) {
	for (int l = 1; l + len - 1 <= n; l++) {
		int r = l + len - 1;
		ll k = (ll)len * a[r] - (pre[r] - pre[l - 1]);
		if (k <= m) return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	int L = 1, R = n, ans = 1;
	while (L <= R) {
		int mid = (L + R) >> 1;
		if (check(mid)) L = mid + 1, ans = mid;
		else R = mid - 1;
	}
	cout << ans << "\n";
	return 0;
}
