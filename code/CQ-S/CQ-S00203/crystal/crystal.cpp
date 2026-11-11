#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int N = 5e5 + 10;

int n, m;
ll a[N], s[N];
ll ans = 0;

ll check(ll i) {
	ll l = 1, r = i;
	ll res = 1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (mid * a[i] - (s[i] - s[i - mid]) <= m) {
			res = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	
	return res;
}

int main(int argc, char *argv[]) {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i ++ ) ans = max(ans, check(i));
	cout << ans << "\n";
	return 0;
}
