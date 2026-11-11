#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool hw(string s){
	string t=s;
	reverse(s.begin(),s.end());
	return t==s;
}
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	ll t;
	cin>>t;
	string s="";
	for(ll i=1;i<=t;i++){
		ll a;
		char b;
		cin>>a>>b;
		for(ll i=1;i<=a;i++){
			s+=b;
		}
	}
	ll l=s.size(),c=0;
	for(ll i=l-1;i>=0;i--){
		if(s[i]!=s[l-i-1]){
			c++;
			s[i]=s[l-i-1];
		}
	}
	cout<<c;
	return 0;
}
