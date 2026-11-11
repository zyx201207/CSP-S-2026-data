//GZ-J00081 贵阳市第一中学 王羿翔
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll n, m; cin >> n >> m;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	vector<ll> ans(m + 1, 0);
	for (ll i = 0; i < n; i++) {
		vector<ll> tmp;
		for (ll j = i; j < n; j++) {
			ll las = -1;
			for (ll k = 0; k < tmp.size(); k++) if (tmp[k] == a[j]) {
				las = k; break;
			}
			if (las != -1) {
				ll cnt = tmp.size() - las;
				while (cnt--) tmp.pop_back();
			}
			//cout << i << ' ' << j << '\n';
			tmp.push_back(a[j]);
			//for (auto x : tmp) cout << x << ' '; cout << '\n';
		}
		for (auto x : tmp) ans[x]++;
	}
	for (ll i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
