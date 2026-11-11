#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,l;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);cout.tie(0);	
	cin>>n;
	for(ll i = 1 ; i <= n ; i ++){
		ll a;
		char x;
		cin>>a>>x;
		for(ll j = 1 ; j <= a ; j ++){
			s+=x;
		}
	}
	ll l=0;
	while(l<=s.size()/2){
		if(s[l]!=s[s.size()-1-l]){
			ans++;
		}
		l++;
	}	
	cout<<ans;
}



