//GZ-J00084 ∏∂Í¿‘Û 
#include<bits/stdc++.h>
#define ll long long
#define vec vector
#define str string
#define pll pair<ll, ll>
using namespace std;

const ll N = 2e5 + 5;

ll a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	ll n, m;
    vec<ll> s;
	cin >> n >> m;
	for(ll i = 1;i <= n;i++)
	    cin >> a[i], s.push_back(a[i]);
	    
	ll ans = 0;
	
	for(ll i = 30;i >= 0;i--) {
		ll cnt = 0;
		vec<ll> ns = s;
		for(ll j = 0;j < n;j++) {
			if(s[j] == -1)
			    continue;
			if(((s[j] >> i) & 1) == 1)
			    cnt++;
			else ns[j] = -1;
		}
		if(cnt >= m) s = ns, ans += (1 << i);
	}
	
	cout << ans << endl;
	
	return 0;
}
