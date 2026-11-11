#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,cnt=0;
	cin>>n;
	s=" ";
	for(ll i=1;i<=n;i++){
		ll a;
		char c;
		cin>>a>>c;
		for(ll j=0;j<a;j++){
			s+=c;
		}
		
	}
	ll l=s.length()-1;
	for(ll i=1;i<=l/(ll)2;i++){
		if(s[i]==s[l+1-i])continue;
		cnt++;
	}
	cout<<cnt<<"\n";
	
	return 0;
}
