#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;

bool comp(ll a,ll b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    
    cin>>n>>m;
    
    
    vector<ll>shu(n);
    ll maxx=0,ji=0,ans=0;
    
    for(ll i=0;i<n;i++){
    	cin>>shu[i];
    	
    	if(shu[i]>maxx)maxx=shu[i];
    	ji=(ji&shu[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(n==m){
		cout<<ji;
		return 0;
	}
	
	
	for(ll i=0;i<n;i++){
		ll x=shu[i];
		for(ll j=i+1;j<i+m;j++)x=(x&shu[j]);
	
		if(x>ans)ans=x;
	}
	
	sort(shu.begin(),shu.end());
	
		for(ll i=0;i<n;i++){
		ll x=shu[i];
		for(ll j=i+1;j<i+m;j++)x=(x&shu[j]);
	
		if(x>ans)ans=x;
	}
	
		sort(shu.begin(),shu.end(),comp);
	
		for(ll i=0;i<n;i++){
		ll x=shu[i];
		for(ll j=i+1;j<i+m;j++)x=(x&shu[j]);
	
		if(x>ans)ans=x;
	}
	 cout<< ans;
    
	return 0;
}
