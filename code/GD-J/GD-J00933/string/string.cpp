#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll q,n;
string s,s1;
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>q;
	while(q--){
		ll p;
		char a;
		cin>>p>>a;
		n+=p;
		for(ll i=1;i<=p;i++)s+=a;
	}
	for(ll i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	for(ll i=0;i<=s.size()-1;i++){
		if(s[i]!=s1[i]){
			ans++;
			s1[i]=s[i];
			s[n-i-1]=s[i];
		}
	}
	cout<<ans;
	return 0;
}
