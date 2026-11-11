#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a;
char b;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a>>b;
		for(ll j=1;j<=a;j++){
			s+=b;
		}
	}
	ll len=s.size(),cnt=0;
	for(ll i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
