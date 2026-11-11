#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){  
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	string s="",s1="";
	while(n--){
		ll t;
		cin>>t;
		string a;
		cin>>a;
		while(t--){
			s+=a;
			s1=a+s1;
		}	
	}
	ll ans=0;
	ll len=s.size();
	for(ll i=0;i<len;i++){
		if(s[i]!=s1[i])ans++;
	}
	cout<<ans/2;
	return 0;
}
