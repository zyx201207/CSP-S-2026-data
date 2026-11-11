#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[2000];
ll ycl[33];
void cl(ll x){
	ll g = x;
	ll is = 0;
	while(g){
		if(g & 1){
			ycl[is] += 1;	
		}
		is ++;
		g /= 2;
	}
}

ll ksm(ll a, ll p){
	ll res = 1;
	while(p){
		if(p & 1){
			res = res * a; 
		}
		p /= 2;
		a = a * a;
	}
	return res;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; i ++){
		cin >> a[i];
		cl(a[i]);	
	}
	ll ans = 0;
	for(ll i = 0; i <= 31; i ++){
		if(ycl[i] >= m){
			ans += ksm(2, i);
		}
	}
	cout << ans;
	return 0;
}
