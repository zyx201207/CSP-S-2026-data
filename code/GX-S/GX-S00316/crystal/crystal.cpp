#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500007;
int n, ans;
ll a[maxn], s[maxn], m;
bool check(int l, int r) {
	return (r - l + 1) * a[r] - (s[r] - s[l - 1]) <= m;
}
int calc(int x) {
	int l = 1, r = x, mid, res = x;
	for (; l <= r; ) {
		mid = (l + r) >> 1;
		if (check(mid, x)) r = mid - 1, res = mid;
		else l = mid + 1;
	}
	return x - res + 1;
}
int main(void) {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		ans = max(ans, calc(i));
	}
	cout << ans << "\n";

	return 0;
}