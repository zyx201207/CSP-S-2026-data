#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 10;
ll n, m, a[MAXN], Sum[MAXN];
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) Sum[i] = Sum[i - 1] + a[i];
	ll l = 1, r = n;
	while (l <= r) {
		ll mid = (l + r) >> 1, flag = false;
		for (int i = mid; i <= n; ++ i) {
			ll sum = Sum[i - 1] - Sum[i - mid - 1];
			if ((mid - 1) * a[i] - sum <= m) {
				flag = true;
				break;
			}
		}
		if (flag) l = mid + 1;
		else r = mid - 1;
	}
	cout << r;
	return 0;
}
