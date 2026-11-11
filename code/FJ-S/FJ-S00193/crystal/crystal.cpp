#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long  ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ll n, m;
	cin >> n >> m;
	
	vector<ll> a(n + 1);
	vector<ll> s(n + 1);
	
	ll minx = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		minx = min(a[i], minx);
	}
	
	sort(a.begin() + 1, a.end());
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i];
	}
	
	ll ans = 0;
	for (ll r = 2; r <= n; ++r) {
		ll rx = r;
		ll lx = 1;
		ll mid = 0;
		ll cur = a[r];
		while (lx < rx) {
			mid = (lx + rx) / 2;
			
			ll pre = s[r - 1] - s[mid - 1];
			ll sub = cur - pre;
			
			if (pre <= cur && sub <= m) {
				ans = max(ans, rx - lx);
			}
			
			if (sub == m) {
				break;
			}
			
			if (sub > m) {
				rx = mid - 1;
			} else { // sub < m
				lx = mid + 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

