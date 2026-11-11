#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans,zd,b[200005];
string a;
map<ll,char>mp;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll x;
		char y;
		cin>>x>>y;
		b[i]=x;
		mp[i]=y;
		zd=__gcd(x,zd);
	}
	for(ll int i=1;i<=n;i++){
		ll x=b[i]/zd;
		ans+=x;
		for(ll j=1;j<=x;j++){
			a+=mp[i];
		}
	}
	ll l=0,r=ans-1;
	ll ans=0;
	while(l<r){
		if(a[l]!=a[r])ans++;
		l++;
		r--;
	}
	cout<<ans*zd;
	return 0;
}
