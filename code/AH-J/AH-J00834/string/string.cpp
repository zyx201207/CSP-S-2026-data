#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//ll a[200005];
//char ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,m=0;
	string s=" ";
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll a;
		char ch;
		cin>>a>>ch;
		m+=a;
		for(ll i=1;i<=a;i++){
			s+=ch;
		}
	}
	ll cnt=0;
	for(ll i=1;i<=m/2;i++){
		if(s[i]!=s[m-i+1]) cnt++;
	}
	cout<<cnt;/*
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		m+=a[i];
	}
	m/=2;
	ll l,z,r,x=0;
	for(ll i=1;i<=n;i++){
		x+=a[i];
		a[i]=x;
		if(x>m){
			l=i-1;
			z=i;
			r=i+1;
			break;
		}
	}
	ll cnt=0;
	while(l){
		if(z==r-1){
			if(a[z]-m>m-a[l]) cnt+=a[z]-m+1;
		}
		while(a[r]-m<m-a[l]){
			cnt+=a[r]-a[r-1]+1;
			r++;
		}
		l--;
	}
	cout<<cnt;*/
	return 0;
}
