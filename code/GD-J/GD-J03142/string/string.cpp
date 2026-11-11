#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,len=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll a;
		char c;
		cin>>a>>c;
		for(ll j=1;j<=a;j++){
			s[len]=c;
			len++;
		}
	} 
	ll cnt=0;
	for(int i=0;i<=len-1-i;i++){
		if(s[i]!=s[len-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 

