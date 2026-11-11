#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=2e5+5;
ll a[N];
char c[N];
string s="";
bool hw()
{
	ll l=s.size();
	for(int i=0;i<l/2;i++)
	{
		ll j=l-1-i;
		if(s[i]!=s[j])
			return false;
	}
	return true;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(ll j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	
	if(hw())
	{
		cout<<"0";
		return 0;
	}
	
	ll l=s.size();
	ll ans=0;
	for(ll i=0;i<l/2;i++)
	{
		ll j=l-1-i;
		if(s[i]!=s[j])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
