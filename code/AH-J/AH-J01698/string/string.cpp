#include<bits/stdc++.h>
#define ll unsigned long long
#define N 200005
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	cin>>n;
	string s="";
	for(ll i=1;i<=n;i++)
	{
		ll k;
		char p;
		cin>>k>>p;
		for(ll j=1;j<=k;j++)
		{
			s+=p;
		}
	}
	ll ans=0;
	ll m=s.size()-1;
	for(ll i=0;i<=m;i++)
	{
		if(s[i]!=s[m-i])
			ans++;
	}
	cout<<ans/2;
	return 0;
}
