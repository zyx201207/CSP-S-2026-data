//×ñÒåËÄÖĞ ÑîºÆ³½ GZ-S00093 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll a[N], s[N], realans, d;
set<ll> t;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1,greater<ll>());
	for (int i = 2; i <= n; i++) {
		t.insert(a[i-1]-a[i]);
		d = a[i-1]-a[i];
	} 
	if (t.size()==1) {
		ll need = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			need+=d*i;
			need-=d;
			if (m < need) {
				cout << i-1;
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ll need = 0, ans = 0;
		for (int j = 0; j+i <= n; j++) {
			need += (a[i]-a[i+j]);
			if (m <= need) {
				ans = j+1;
				break;
			}
		}
		realans = max(ans,realans);
	}
	cout << realans;
	return 0;
}

