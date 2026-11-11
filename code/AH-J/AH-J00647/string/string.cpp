#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	string s="";
	cin>>n;
	ll cnt;
	char c;
	if(n==1){
		cin>>cnt>>c;
		cout<<0;
	}
	for(ll i=1;i<=n;i++){
		cin>>cnt>>c;
		for(ll j=1;j<=cnt;j++){
			s+=c;
		}
	}
	string a=s;
	reverse(s.begin(),s.end());
	if(a==s){
		cout<<0;
	}
	return 0;
}
