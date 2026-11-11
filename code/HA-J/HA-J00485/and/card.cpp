#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ifstream fin ("card.in");
ofstream fout ("card.out");
#define cin fin
#define cout fout

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, m;
	cin >> n >> m;
	
	vector<ll> a(n + 1);
	for (ll i = 1; i <= n; i++) cin >> a[i];
	
	vector<ll> dk;
	for (ll tmp = 1; tmp <= m; tmp++) {
		ll ans = 0;
		for (ll i = 1; i <= n; i++) {
			for (ll j = i; j <= n; j++) {
				dk.push_back(a[j]);
				for (ll k = 0; k < dk.size() - 1; k++) {
					if (dk[k] == tmp) ans++;
					if (dk[k] == a[j]) for (ll l = k; l < j; l++) dk[l] = 0;
				}
			}
		}
		cout << ans << ' ';
	}
	
	return 0;
}
