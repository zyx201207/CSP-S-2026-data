#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ll n , m;
	cin >> n >> m;
	vector<ll> a;
	for(ll i = 0; i < n; i++){
		ll a1;
		cin >> a1;
		a.push_back(a1);
	}
	
	sort(a.begin() , a.end() , greater<ll>());
	ll ans = a[0];
	for(ll i = 1; i < m; i++){
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}
