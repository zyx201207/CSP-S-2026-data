#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
struct node{
	ll x;
	char y;
}a[100005];
ll b[100005];
char c[100005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		b[i]=a[i].x;
		c[i]=a[i].y;
	}
	ll d=b[1];
	for(ll i=2;i<=n;i++)
		d=__gcd(d,b[i]);
	for(ll i=1;i<=n;i++)
		b[i]/=d;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=b[i];j++)
			s+=c[i];
	}
	ll l=s.size();
	ll ans=0;
	for(ll i=0;i<(l+1)/2;i++){
		if(s[i]!=s[l-i-1])
			ans++;
	}
	cout<<ans*d;
	return 0;
}
