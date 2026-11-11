#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5 + 10;
ll n, m;
ll a[5 * N], s[5 * N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(ll i = n; i >= 1; i--) {
		s[i] = s[i + 1] + a[i];
	}
	ll maxx = LLONG_MIN;
	for(ll i = 2; i <= n; i++) {
		ll l = 0, r = n;
		while(l + 1 < r) {
			ll mid = (l + r) / 2;
			if((a[i] * (i - mid) + s[i] - s[mid] <= m)) {
				r = mid; 
			}
			else l = mid;
		}
		maxx = max(maxx, i - r + 1);
	}
	cout << maxx;
	
	return 0;
}
