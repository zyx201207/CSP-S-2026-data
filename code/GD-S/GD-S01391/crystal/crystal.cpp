#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAXN = 5e5 + 5;
ll n, m, a[MAXN];

inline ll check(ll mid) {
	ll tar = mid, res = 0, rem = m;
//	cout << "check " << mid << "..." << endl;
	for (ll i = 1; i <= n && a[i] <= tar; i++) {
		if (rem - (tar - a[i]) >= 0) {
//			cout << rem << " >= " << tar - a[i] << ", rem = " << rem - (tar - a[i]) << "." << endl;
			rem -= tar - a[i], res++;
		} else break;
	}
//	cout << "tar = " << a[mid] << ", res = " << res << endl << endl;
	return res;
}

inline ll binarySearch() {
	ll ans = -INF, l = 1, r = n + 1;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		ll val = check(a[mid]);
		if (val > ans) {
			ans = val, l = mid + 1;
		} else r = mid - 1;
	}
	return ans;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);

	cout << binarySearch() << endl;
	return 0;
}

