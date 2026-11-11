//GZ-S00060 贵阳市第一中学 王羿翔 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void ji() {
	ll n, d; cin >> n >> d;
	vector<ll> a(n + 1);
	for (ll i = 1; i <= n; i++) cin >> a[i];
	ll t = d / (a[2] - a[1]);
	if (t == 0 || t == 1) cout << 0;
	else cout << max(n - (t + t - 1), 0LL);
	cout << '\n';
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll c, t; cin >> c >> t;
	while (t--) ji();
	return 0;
}
