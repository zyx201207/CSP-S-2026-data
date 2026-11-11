#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 5;
ll a[N], b[N][35], c[N], d[N];
void f(ll x, ll y) {
	ll cnt = 31;
	for(ll i = 1; i <= 30; i++) c[i] = 0;
	while(x) {
		c[--cnt] = x % 2;
		x /= 2;
	}
	for(ll i = 1; i <= 30; i++) b[y][i] = c[i];
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) {
		cin >> a[i];
		f(a[i], i);
	}
	ll len = 0;
	memset(c, 0, sizeof(c));
	ll x = 1, ans = 0;
	while(x <= 30) {
		if(!len) {
			for(ll i = 1; i <= n; i++) {
				if(b[i][x]) c[++len] = i;
			}
			x++;
			if(len >= m) {
				ans = pow(2, 31 - x);
				continue;
			}
			else {
				len = 0;
				memset(c, 0, sizeof(c));
			}
			continue;
		}
		else {
			memset(d, 0, sizeof(d));
			ll cnt = 0;
			for(ll i = 1; i <= len; i++) {
				if(b[c[i]][x]) d[++cnt] = c[i];
			}
			if(cnt >= m) {
				for(ll i = 1; i <= cnt; i++) c[i] = d[i];
				ans += pow(2, 30 - x);
				len = cnt;
			}
		}
		x++;
	}
	cout << ans << endl;
	return 0;
}
