// ЭѕУћбя GZ-J00087 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n + 1);
	for (ll i = 1; i <= n; ++i)
		cin >> a[i];
		
	vector<ll> ans(m + 1);
	for (ll i = 1; i <= n; ++i) {
		ll cur = i;
		vector<ll> b(m + 1, 0), c(n + 1);
		for (ll j = i; j <= n; ++j) {
			if (b[a[j]] == 0) {
				b[a[j]] = cur, c[cur] = a[j];
				++cur;
			} else {
				for (ll k = b[a[j]] + 1; k < cur; ++k)
					b[c[k]] = 0;
				cur = b[a[j]] + 1;
			}
		}
		for (ll j = i; j < cur; ++j)
			ans[c[j]]++;
	}
	
	for (ll i = 1; i <= m; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
}
