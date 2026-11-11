#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[100000005];
map<long long,long long>mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>mp[i];
	}
	ll ans=1,k;
	for(ll i=2;i<=n;i++){
		k=mp[i];
		s[i]=k-mp[i-1];
		if(m<s[i])break; 
		m-=s[i];
		mp[i-1]+=s[i];
	}
	for(ll i=1;i<=n-1;i++){
		s[i]=mp[i+1]-mp[i];
		if(m<s[i])break;
		mp[i]+=s[i];
	}
	for(ll i=1;i<=n-1;i++){
		if(mp[i]==mp[i+1])ans++;
	}
	cout<<ans;
	
	return 0;
}
