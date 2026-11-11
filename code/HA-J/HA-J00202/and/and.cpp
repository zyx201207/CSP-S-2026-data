#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[200005];
string ab(ll x){
	string s;
	while(x){
		s+=x%2+'0';
		x/=2;
	}
	return s;
}
string abc(string x,string y){
	string c;
	ll la=x.size();
	ll lb=y.size();
	for(ll i=0;i<max(la,lb);i++){
		if(x[i]==y[i])
			c+='1';
		else
			c+='0';
	}
	return c;
}
ll abcd(string x){
	ll l=x.size();
	ll s=0;
	for(ll i=0;i<l;i++){
		ll c=1;
		for(ll j=0;j<i;j++)
			c*=2;
		s+=(x[i]-'0')*c;
	}
	return s;
}
ll abcde(int x){
	ll ans=a[1];
	for(ll i=2;i<=n;i++){
		if(i!=x)
			ans=abcd(abc(ab(ans),ab(a[i])));
		else
			continue;
	}
	return ans;
}
int main(){
	freopen("and3.in","r",stdin);
	freopen("and4.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		ll ans=-0x3f3f3f3f;
		for(ll i=1;i<=n;i++)
			ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==2){
		ll ans=-0x3f3f3f3f;
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<=n;j++)
				ans=max(ans,abcd(abc(ab(a[i]),ab(a[j]))));
		}
		cout<<ans;
		return 0;
	}
	else if(m==n){
		ll ans=a[1];
		for(ll i=2;i<=n;i++)
			ans=abcd(abc(ab(ans),ab(a[i])));
		cout<<ans;
		return 0;
	}
	else if(m==n-1){
		ll ans=-0x3f3f3f3f;
		for(ll i=1;i<=n;i++)
			ans=max(ans,abcde(i));
		cout<<ans;
	}
	return 0;
}
