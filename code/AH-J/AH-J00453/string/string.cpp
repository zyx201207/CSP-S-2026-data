#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s="";
ll n,p;
char ch;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>p>>ch;
		while(p--){
			s+=ch;
		}
	}
	string s2="";
	for(ll i=s.size()-1;i>=0;i--){
		s2+=s[i];
	}
	ll ans=0;
	for(ll i=0;i<(ll)s.size();i++){
		if(s[i]!=s2[i]){
		    ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
