#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll a;
	cin>>a;
	string d="";
	for(ll i=0;i<a;i++){
		ll b;
		cin>>b;
		char c;
		cin>>c;
		for(ll j=0;j<b;j++){
			d+=c;
		}
	}
	ll t=0;
	ll x=d.length();
	for(ll i=0;i<(d.length()+1)/2;i++){
		if(d[i]!=d[x-1-i]) t++;
	}
	cout<<t;
	return 0;
}
