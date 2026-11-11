#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	ll n;
	ll ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;
		char c;
		cin>>x>>c;
		for(int i=1;i<=x;i++){s=s+c;}
	}
	s=' '+s;
	//cout<<s<<"\n";
	for(int i=1;i<=s.size()/2;i++){
		//cout<<s[i]<<" "<<s[s.size()-i]<<"\n";
		if(s[i]!=s[s.size()-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
