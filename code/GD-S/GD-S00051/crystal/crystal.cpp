#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
ll a[1000100];

bool check(ll mid){
	ll sum = 0,cnt = 0;
	for(ll i = 1;i<=n;i++){
		if(a[i]!=a[mid]){
			sum += a[i];
			cnt++; 
		}
		else break;
	}
	return m >= a[mid]*cnt-sum;
}

void solve(){
	cin >> n >> m;
	for(ll i = 1;i<=n;i++)cin >> a[i];
	ll l = 1,r = n;
	while(l<r){
		ll mid = l+(r-l)/2;
		if(check(mid)){
			l = mid+1;
		}
		else r = mid;
	}
	cout << l-1;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
} 
