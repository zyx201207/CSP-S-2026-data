#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,c;
string s; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll t;
		char c;
		cin>>t>>c;
		for(ll j=1;j<=t;j++) s+=c;
	}
	for(ll i=0,j=s.size()-1;i<s.size()/2;i++,j--){
		if(s[i]!=s[j]) c++;
	}
	cout<<c;
	return 0;
} 
