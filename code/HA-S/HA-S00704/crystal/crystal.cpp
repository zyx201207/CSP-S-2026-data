#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll N = 5e5 + 5; 
ll n,m;
ll a[500005];
ll qzh[500005];

ll he(ll l, ll r){
	return qzh[r] - qzh[l - 1];
}

bool check(ll x){
	for(ll i = 1; i <= n - x + 1; i ++){
		ll r = i + x - 1;
		ll s = a[r];
		ll h = he(i, r);
		if(s * x - h <= m) return 1; 
	}
	return 0;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(ll i = 1; i <= n; i ++) qzh[i] = qzh[i-1] + a[i];
	ll l = 0, r = n;
	while(l<= r){
		ll mid = (l + r) / 2;
		//cout << mid << endl;
		if(check(mid)){
			l = mid + 1;
		}else{
			r = mid - 1; 
		}
	}
	cout << r;
	return 0;
} 

/*
5 5
1 2 4 8 9

*/

