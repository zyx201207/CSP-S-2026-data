#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=1e8+10;
ll a[N],ans;
char c[N];
bool f[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s;
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++) 
	{
		
		cin>>a[i]>>c[i];
	}
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<a[i];j++)
		{
			s+=c[i];
		}
	}
	ll leg=s.size();
	for(ll i=0;i<n-1;i++) 
	{
		if(c[i]==c[i+1]) 
		{
			cout<<"0";
			return 0;
		}
		
	}
	for(ll i=0;i<leg-1;i++)
	{
		if(s[i]==s[i+1]) f[i]=1;
		else f[i]=f[i-1];
	}
	
	for(ll i=0;i<leg;i++)
	{
		if(f[i]==0) ans++;
	}
	cout<<ans+1;
	return 0;
}
