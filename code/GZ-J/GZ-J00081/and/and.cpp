//GZ-J00081 贵阳市第一中学 王羿翔
//T3 100 points
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (1LL << 32) - 1;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll n, k; cin >> n >> k;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	vector<ll> s;
	ll bit = 32;
	for ( ; bit >= 0; bit--) {
		for (auto x : a) if (x & (1ll << bit)) s.push_back(x);
		if (s.size() >= k) break;
		s.clear();
	}
	//for (auto x : s) cout << x << ' '; cout << endl;
	if (bit < 0) {
		cout << 0; return 0;
	}
	vector<ll> t;
	auto solve = [&]() -> void {
		for ( ; bit >= 0; bit--) {
			for (auto x : s) if (x & (1ll << bit)) t.push_back(x);
			if (t.size() < k) {
				t.clear(); break;
			}
			s = t;
			t.clear();
		}
	};
	while (bit >= 0) {
		bit--; solve();
	}
	ll ans = INF;
	for (ll i = 0; i < k; i++) ans &= s[i];
	//for (auto x : s) cout << x << ' '; cout << endl;
	cout << ans;
	return 0;
}
