// 17:51
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 5010;
ll c, t, n, d, ans;
array<ll, N> x, l, nxt;
array<array<ll, N>, N> sl, sn;
bool check(ll s, ll t) {
	return sn[s][t - 1] - sl[t][s + 1] == 1;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> c >> t;
	while(t--) {
		ans = 0;
		cin >> n >> d;
		for(ll i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if(c == 11 || c == 12) {
			ll dlt = x[2] - x[1];
			if(dlt * 2 > d) {
				cout << "0\n";
			} else {
				cout << max(0ll, n - (d / dlt) * 2 + 1) << '\n';
			}
			continue;
		}
		for(ll i = 1, j = 1; i <= n; i++) {
			while(j <= n && x[j] - x[i] <= d) {
				l[j] = i, j++;
			}
			nxt[i] = j - 1;
		}
		for(ll i = 1, j; i <= n; i++) {
			for(ll k = 1; k <= n; k++) {
				sn[i][k] = sl[i][k] = 0;
			}
			j = nxt[i];
			sn[i][j] += j;
			while(j != nxt[j]) {
				j = nxt[j];
				sn[i][j] += j;
			} 
			for(ll k = i; k <= n; k++) {
				sn[i][k] += sn[i][k - 1];
			}
			j = l[i];
			sl[i][j] += j;
			while(l[j] != j) {
				j = l[j];
				sl[i][j] += j;
			}
			for(ll k = i; k; k--) {
				sl[i][k] += sl[i][k + 1];
			}
		}
		for(ll i = 1; i <= n; i++) {
			for(ll j = i + 1; j <= n; j++) {
				if(nxt[j - 1] == j - 1) {
					break;
				}
				ans += check(i, j);
			}
		}
		cout << ans << '\n';
	}
}
