#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,a,t=0;
	char b;
	string s="";
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a>>b;
		t+=a;
		for(ll j=1;j<=a;j++){
			s+=b;
		}
	}
	if(t%2!=0){
		ll cnt1=0,cnt2=0;
		string x=s.substr(0,t/2);
		string y=s.substr(t/2+1,t/2);
		for(ll i=0;i<t/2;i++){
			if(y[i]!=s[i]) cnt1++;
		}
		for(ll i=t/2+1;i<t;i++){
			if(x[i]!=s[i]) cnt2++;
		}
		if(cnt1>cnt2) cout<<cnt2;
		else cout<<cnt1;
	}
	else{
		ll cnt1=0,cnt2=0,z=0;
		string x=s.substr(0,t/2);
		string y=s.substr(t/2,t/2);
		for(ll i=0;i<t/2;i++){
			if(s[i]!=y[i]) cnt1++;
		}
		for(ll i=t/2;i<t;i++){
			if(s[i]!=x[++z]) cnt2++;
		}
		if(cnt1>cnt2) cout<<cnt2;
		else cout<<cnt1;
	}
	return 0;
}
