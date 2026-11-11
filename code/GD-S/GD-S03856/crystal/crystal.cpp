#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using II = __int128;

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);	
	
	int n; ll m; cin >> n >> m;

	vector<ll> a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.end());
	
	vector<II> c(n + 1);
	for (int i = n - 1; i >= 1; i--) c[i] = a[i + 1] - a[i];
	for (int i = n - 1; i >= 1; i--) c[i] += c[i + 1];
	
	ll ans = 1, f = 1; II co = 0;
	
	for (int i = 2; i <= n; i++) {
		co += (II)f * (a[i] - a[i - 1]);
		f++;
		while (co > m && f > 1) {
			co -= (c[i - f + 1] - c[i]);
			f--;
		}
		ans = max(ans, f);
	}
	
	cout << ans << '\n';
	return 0;
} 
/*
vector<ll> b = a, cnt(n + 1);
	b.erase(unique(b.begin(), b.end()), b.end());
	int nn = b.size() - 1;
	
	for (int i = 1; i <= nn; i++) 
		cnt[i] = (upper_bound(a.begin() + 1, a.end(), b[i]) - 
				  lower_bound(a.begin() + 1, a.end(), b[i]));
	
	ll ans = 1, cost = 0, f = 1;
	
	for (int i = 2; i <= nn; i++){
		cost += f * (b[i] - b[i - 1]); f += cnt[i];
		while (cost > m && f) {
			f--;
			cost -= (b[i] - b[i - 1]);
		} 
		ans = max(ans, f);
		cout << "i = " << i << " f = " << f << " cost = " << cost << '\n';
	}
*/
