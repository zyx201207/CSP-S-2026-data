#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200000];
bool cmp(ll x, ll y){
	return x > y;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	if(m == 1){
		cout << a[1];
		return 0;
	}
	if(m == 2){
		ll maxn = -1e18;
		for(ll i = 1; i <= n; i++){
			for(ll j = i + 1; j <= n; j++){
				maxn = max(maxn, a[i] & a[j]);
			}
		}
		cout << maxn;
		return 0;
	}
	else{
		ll x = a[1];
		for(ll i = 2; i <= m; i++){
			x &= a[i];
		}
		cout << x;
	}
	return 0;
}

