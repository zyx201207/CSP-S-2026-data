#include<bits/stdc++.h>
#define ll long long 
#define db double
using namespace std;
string s="";
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--){
		ll a;
		char c;
		cin>>a>>c;
		for(ll i=1;i<=a;i++) s+=c;			
	}
	ll l=s.length();
	ll cnt=0;
	for(ll i=0;i<=l/2-1;i++){
		ll judge=l-1-i;
		if(s[judge]!=s[i]) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
