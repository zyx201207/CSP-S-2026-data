#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	ll l=0;
	ll i=1;
	string b;
	
	for(ll i=0;i<n;i++){
		ll a;char s;
		cin>>a>>s;
		for(int j=0;j<a;j++){
			b+=s;
		}
		l+=a;
	}
	l-=1;
	ll sum=0;
	for(ll i=0;i<=l/2;i++){
		if(b[i]!=b[l-i]){
			b[l-i]=b[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}