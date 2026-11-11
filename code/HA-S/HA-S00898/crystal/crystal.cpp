#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 10;
using ll = long long;
ll n, a[N], m, w, ans = 1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int l = 1;
	a[0] = a[1];
	for (int i = 1; i <= n; i++) {
		w += (a[i] - a[i - 1]) * (i - l);
		while (w > m) {
			w -= a[i] - a[l];
			l++;
		}
		ans = max(ans, i - l + 1ll);
	}
	cout << ans << endl;
	return 0;
}
