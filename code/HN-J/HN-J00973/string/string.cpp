#include<bits/stdc++.h>
using namespace std;
string s;
#define ll long long
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	s+=1;
	ll a[n+1],sum=0,l=0;
	char c[n+1];
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
		for(ll j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(ll i=1;i<=l/2;i++){
		if(s[i]!=s[l+1-i]){
			++sum;
		}
	}
	cout<<sum;
	return 0;
}
