//GZ-J00084 ∏∂Í¿‘Û 
#include<bits/stdc++.h>
#define ll long long
#define vec vector
#define str string
#define pll pair<ll, ll>
using namespace std;

const ll N = 5e5 + 5;

ll a[N], d[N], ans[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	map<ll, ll> id;
	for(ll i = 1;i <= n;i++)
	    cin >> a[i], id[a[i]] = i;
	
	for(ll i = 1;i <= n;i++) {
		d[i] += d[i-1];
		if(id[a[i]] != i) {
			ll x = d[i];
			d[i] += i - x;
		    d[id[a[i]]] -= i - x;
		}
		ans[a[i]] += i - d[i];
	}
	
	for(ll i = 1;i <= m;i++)
	    cout << ans[i] << " ";
	cout << endl;
	
	return 0;
}
