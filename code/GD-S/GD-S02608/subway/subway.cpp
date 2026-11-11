#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5e2 + 10;
const int ZJY = 5e5 + 10;

ll c, n, m, d, q, a[N], w;

struct jl{
	ll g, t;
}G[ZJY];
void solve() {
	ll x, y, ans = 0, sum = 0; cin >> x >> y;
	ans += a[x], ans += a[y];//≥ı º
	x = min(x, y), y = max(x, y);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if (G[j].g >= x && G[j].g <= y)
				ans += G[j].t;
		}
	}
	cout << ans << '\n';
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		ll k; cin >> k;
		w = k;
		for (int j = 1; j <= k; j++) 
			cin >> G[j].g >> G[j].t;
	}
	while (q--) solve();
	return 0;
} 
