#include <bits/stdc++.h>
using namespace std;
#define L(i, l, r) for (ll i = (l); i <= (r); i ++)
#define R(i, r, l) for (ll i = (r); i >= (l); i --)
using ll = long long;
namespace Sednorote {
	ll n, m;
	const ll N = 1e6 + 5;
	ll a[N], sm[N]; 
	void main() {
		cin >> n >> m;
		L(i, 1, n) cin >> a[i];
		sort(a + 1, a + n + 1);
		L(i, 1, n) sm[i] = sm[i - 1] + a[i];
		ll ans = 0;
		L(i, 1, n) {
			ll l = 1, r = i;
			while (l < r) {
				ll mid = (l + r) >> 1;
				if (a[i] * (i - mid + 1) - (sm[i] - sm[mid - 1]) <= m) r = mid;
				else l = mid + 1;
			}
			ans = max(ans, i - l + 1);
		}
		cout << ans << "\n";
	}
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Sednorote::main();
	return 0;
}

