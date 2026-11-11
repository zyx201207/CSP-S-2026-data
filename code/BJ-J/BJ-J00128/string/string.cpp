#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,len;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string str;
	ll x;
	char ch;
	for(ll i=1;i<=n;i++){
		cin>>x>>ch;
		len+=x;
		while(x--) str+=ch;
	}
	ll ans=0,nxt;
	string s1=str.substr(0,len/2);
	if(len%2==0) nxt=len/2;
	else nxt=len/2+1;
	string s2=str.substr(nxt,len/2);
	for(ll i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]) ans++;
	}
	cout<<ans;
	return 0;
}
