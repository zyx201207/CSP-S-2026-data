#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[200005];
char c[200005];
string s;
ll n;
ll cnt;
ll l=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	
	}
    for(ll i=1;i<=n;i++){
       for(ll j=1;j<=a[i];j++){
       	s+=c[i];
	   }
	}
	for(ll i=0;i<s.size()/2;i++){
	    if(s[i]!=s[s.size()-i-1])cnt++;
	   }cout<<cnt;


	return 0;
}
