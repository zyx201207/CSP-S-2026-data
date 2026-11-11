#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,tot,max_k,cnt;
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;++i){
		ll k;char ch;
		cin>>k>>ch;
		max_k=max(k,max_k);
		for(ll j=1;j<=k;++j) s+=ch;
		tot+=k;
	}
	if(n*max_k<=100000000){
		for(ll i=(tot+1)/2+1;i<=tot;++i){
			if(s[i]!=s[tot+1-i]) ++cnt;
		}
	}
	cout<<cnt;
	return 0;
}
