//GZ-J00006 观山湖中学 吴俊辰 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	string s="";
	for(ll i=0;i<n;i++){
		ll a;char c;
		cin>>a>>c;
		for(ll j=0;j<a;j++)s+=c;
	}
	ll ans=0;
	for(ll i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}
