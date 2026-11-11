#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll a[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m; cin>>n>>m;
	bool B=true;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll _=a[2]-a[1];
	for(ll i=2;i<=n;i++){
		if(a[i]-a[i-1]!=_){
			B=false;
			break;
		}
	}
	if(B){
		ll x=0;
		ll id=0;
		for(ll i=_;i<=(n-1)*_;i+=_){
			//cout<<i<<'\n';
			id++;
			if(m<=x){
				id--;
				break;
			}
			x+=i;
		}
		cout<<id;
		return 0;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll x=0,k=0;
		for(ll j=i;j>=1;j--){
			x+=(a[i]-a[j]);
			k++;
			if(x>m){
				k--;
				break;
			}
		}
		ans=max(ans,k);
	}
	cout<<ans;
	
	
	return 0;
} 
/*

	m=8;
	-3 -1 2 2 7
	-3 -1 2 2 7

*/
