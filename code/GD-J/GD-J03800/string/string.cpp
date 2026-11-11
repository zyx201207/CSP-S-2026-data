#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5 + 10;
ll a[2 * N], b[2 * N];
char c[2 * N], cb[2 * N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int t = 1;
	for(ll i = 1; i <= n; i++) {
		bool flag = 0;
		while(c[i] == c[i + 1]) {
			b[t] += a[i];
			flag = 1;
			i++;
		}
		if(flag) b[t] += a[i]; 
		if(!flag) b[t] = a[i];
		cb[t] = c[i], t++;
	}
	t--;
	n = t;
	ll ans = 0;
	for(ll i = 1, j = n; i < j; i++, j--) {
		if(b[i] == b[j] && cb[i] != cb[j]) {
			ans += b[i];
			b[i] -= b[i];
			b[j] -= b[j];
		}
		else if(cb[i] != cb[j]){
			if(b[i] < b[j]) {
				while(b[j] >= 0 && i < j) {
					if(cb[j] != cb[i]) {
						ans += b[i];
					}
					ll x = b[i];
					b[i] -= min(b[i], b[j]);
					b[j] -= x;
					i++;
				}
				i--; 
			} 
			else { 
				while(b[i] >= 0 && i < j) {
					if(cb[i] != cb[j]) {
						ans += b[j];
					}
					ll x = b[j];
					b[j] -= min(b[j], b[i]);
					b[i] -= x;
					j--;
				}
				j++; 
			}
		}
	} 
	cout << ans;

	return 0;
}
// 5 2 c 5 d 9 a 1 b 7 a

