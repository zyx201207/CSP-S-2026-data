#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	ll cnt=0;
	cin>>n;
	string s;
	for(ll i=1;i<=n;i++){
		ll a;
		char ch;
		cin>>a>>ch;
		cnt+=a;
		string s1(a,ch);
		s+=s1;
	}
	ll num=cnt/2;
	ll ans=0;
	for(ll i=1;i<=num;i++){
		if(s[i-1]!=s[cnt-i])ans++;
		else continue;
	}cout<<ans;
	return 0;
}
