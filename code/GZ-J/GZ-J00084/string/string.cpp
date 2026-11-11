//GZ-J00084 ∏∂Í¿‘Û 
#include<bits/stdc++.h>
#define ll long long
#define vec vector
#define str string
#define pll pair<ll, ll>
using namespace std;

const ll N = 2e5 + 5;

ll a[N];
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	ll n;
	cin >> n;
	for(ll i = 1;i <= n;i++)
	    cin >> a[i] >> c[i];
	
	ll ans = 0;
	ll l = 1, r = n;
	while(l < r) {
		ll t = min(a[l], a[r]);
		a[l] -= t, a[r] -= t;
		if(c[l] != c[r]) ans += t;
		if(a[l] == 0) l++;
		if(a[r] == 0) r--;
	}
	
	cout << ans << endl;
	
	return 0;
}
