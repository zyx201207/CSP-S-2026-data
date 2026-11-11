#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , m , a[500005] , cnt[300005];
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(ll i = 1 ; i <= n ; i++) cin >> a[i];
	for(ll i = 1 ; i <= n ; i++){
		vector<ll> v;
		for(ll j = i ; j <= n ; j++){
			ll pos = -1;
			for(ll k = 0 ; k < ll(v.size()) ; k++) if(v[k] == a[j]) pos = k;
			if(pos == -1) v.push_back(a[j]);
			else{
				vector<ll> newv;
				for(ll k = 0 ; k < pos ; k++) newv.push_back(v[k]);
				v = newv;
				v.push_back(a[j]);
			}
		}
		for(ll j = 0 ; j < ll(v.size()) ; j++) cnt[v[j]]++;
	}
	for(ll i = 1 ; i <= m ; i++) cout << cnt[i] << ' ';
	return 0;
}//all for c1~6 solve24p
