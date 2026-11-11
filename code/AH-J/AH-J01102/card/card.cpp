#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;
typedef long long ll;
int a[N], b[N], c[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, m, ans = 0;
	cin >> n >> m;
	for (ll i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	ll t = n;
	while(t--) {
		for (ll i = 1 + ans; i <= n; i ++) {
			for (ll j = 1 + ans; j < i; j ++) {
				if (b[j] == a[i]) {
					for (ll k = j; k < i; k ++) {
						b[k] = 0;
					}
				}
			}
			b[i] = a[i];
		}
		ans ++;
		for (ll i = 1; i <= m; i ++) {
			for (ll j = 1; j <= n; j ++) {
				if (b[j] == i) {
					c[i] ++;
				}
			}
		}
		memset(b, 0, sizeof(b));
	}
	for (ll i = 1; i <= m; i ++) {
		cout << c[i] << " ";
	}
	return 0;
}
