#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ll n,m;
	cin>>n>>m;
	
	vector<ll> num(n);
	for(ll i=0;i<n;i++)cin>>num[i];
	sort(num.begin(),num.end());
	
	if(m>=INT_MAX){
		ll mnum=num[n-1],tm=m,sum=1;
		for(ll ii=n-2;ii>=0;ii--){
			tm-=num[n-1]-num[ii];
			
			if(tm<0)break;
			else sum++;
		}
		cout<<sum;
	}
	
	else{
	ll ans=0;
	for(ll i=n-1;i>=0;i--){
		ll mnum=num[i],tm=m,sum=1;
		
		for(ll ii=i-1;ii>=0;ii--){
			tm-=num[i]-num[ii];
			
			if(tm<0)break;
			else sum++;
		}
		
		ans=max(ans,sum);
	}
	
	cout<<ans;
	}
	
	return 0;
}
