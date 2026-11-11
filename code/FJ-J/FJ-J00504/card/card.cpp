#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 505;
ll vis[N], a[N], b[N], ans[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	bool f = true;
	for(ll i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] < a[i - 1]) f = false;
	}
	if(f) {
		for(ll i = 1; i <= n; i++) ans[a[i]] = i;
		for(ll i = 1; i <= m; i++) cout << ans[i] << " ";
		return 0;
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) b[j] = a[j];
		for(ll j = i; j <= n; j++) {
			if(vis[b[j]]) {
				bool flag = false;
				for(ll k = i; k < j; k++) {
					if(b[k] == b[j]) flag = true;
					if(flag) {
						vis[b[k]]--;
						b[k] = 0;
					}
				}
			}
			vis[b[j]]++;
		}
		for(ll j = i; j <= n; j++) {
			if(b[j] && vis[b[j]]) {
				vis[b[j]] = 0;
				ans[b[j]]++;
			}
		}
	}
	for(ll i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
