#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll a[200009];
string s;
bool b;
char c[200009];
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	ll num=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
		for(ll j=1;j<=a[i];j++) s+=c[i];
	}
	ll ans=0;
	for(ll i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]) b=1;
	}
	if(!b){
		cout<<0;
		return 0;
	}
	ll len=s.size()-1;
	len=(len+1)/2;
	if(s.size()==2){
		if(s[0]==s[1]) cout<<0;
		else cout<<1;
		return 0;
	}
	if(s.size()==3){
		if(s[0]==s[2]) cout<<0;
		else cout<<1;
		return 0;
	}
	for(ll i=0;i!=s.size()-i-1;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
} 
