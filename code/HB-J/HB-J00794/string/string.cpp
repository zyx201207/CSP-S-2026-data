#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,l=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll a;char c;
		cin>>a>>c;
		l+=a;
		for(ll j=1;j<=a;j++)s+=c;
	}
	ll cnt=0;
	for(ll i=0;i<=l/2;i++){
		if(s[i]!=s[l-i-1])cnt++;
	}
	if(l%2==0)cout<<cnt-1;
	else cout<<cnt;
	return 0;
}
