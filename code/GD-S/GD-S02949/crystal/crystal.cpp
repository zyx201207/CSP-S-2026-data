#include <bits/stdc++.h>
#define endl '\n'
#define fn "crystal"
typedef long long ll;
using namespace std;
ll n, m, a[500050], ans = 1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen(fn ".in", "r", stdin);
	freopen(fn ".out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll l = (1 + n) / 2, r = (1 + n / 2);
	ll md = a[l];
	r ++, l --;
	while(m > 0){
		ll an = md - a[l], bn = a[r] - md;
		if (an >= bn){
			if (m >= bn){
				m -= bn;
				ans ++;
				r ++;
			}
			else break;
		}
		else {
			if (m >= an){
				m -= an;
				ans ++;
				l --;
			}
			else break;
		}
	}
	cout << ans;
	return 0;
}
