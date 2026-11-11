#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n;
string s="";
ll cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll a;
		char c;
		cin>>a;
		cin>>c;
		for(ll j=1;j<=a;j++){
			s=s+c;
		}
	}
	ll sum=s.size();
	for(ll i=0;i<sum/2;i++){
		if(s[i]!=s[sum-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
