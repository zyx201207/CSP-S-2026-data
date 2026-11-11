//GZ-J00022,商梓辰，贵阳市第三中学
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;cin>>n;
	string s="";
	for(ll i=1;i<=n;i++){
		ll a;char c;
		cin>>a>>c;
		for(ll j=1;j<=a;j++){
			s+=c;
		}
	}
	string t="";
	for(ll i=(ll)s.size()-1;i>=0;i--){
		t+=s[i];
	}
	ll sum=0;
	for(ll i=0;i<(ll)s.size()/2;i++){
		if(s[i]!=t[i]) sum++;
	}
	cout<<sum<<endl;
	return 0;
	 
} 
