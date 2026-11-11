#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 5e5 + 7;

ll n, m, a[N], pre[N], ans;

int main() {
//	crystal
//	freopen("crystal4.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(ll i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	ans = 1;
	for(ll i = 1; i <= n; i++) {
		ll l = 1, r = i, res = 0;
		while(l <= r) {
			ll mid = (l + r) >> 1;
			if((i - mid + 1) * a[i] - (pre[i] - pre[mid - 1]) <= m) {
				r = mid - 1, res = mid;
			} else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans;
	return 0;
}
