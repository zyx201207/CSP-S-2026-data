#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//8f
const int maxn = 2e6 + 5;

ll n, d, c, t;
ll x[maxn];

//ll scan() {
//	ll k = 1, s = 0, c = gge
//}

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) x[i] = 0;
	for (int i = 1; i <= n; i++) cin >> x[i];
	ll r = x[2] - x[1];
	if (d < 2ll * r) cout << 0 << '\n';
	else cout << max(1ll * 0, n - 2 * (d / r) + 1) << '\n';
//	cout << d << " " << n << " " << x[2] - x[1] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--) solve();
	
	return 0;
}
