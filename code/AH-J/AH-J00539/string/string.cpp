#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,sum=0;
	cin>>n;
	vector<ll> a(n);
	vector<char> c(n);
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	ll ans=0;
	while(a.size()>1)
	{
		if(a[0]<a[a.size()-1])
		{
			if(c[0]!=c[a.size()-1]) ans+=a[0];
			a[a.size()-1]-=a[0];
			a.erase(a.begin());c.erase(c.begin());
		}
		else if(a[0]>a[a.size()-1])
		{
			if(c[0]!=c[a.size()-1]) ans+=a[a.size()-1];
			a[0]-=a[a.size()-1];
			a.erase(a.begin()+a.size()-1);
			c.erase(c.begin()+c.size()-1);
		}
		else 
		{
			if(c[0]!=c[a.size()-1]) ans+=a[0];a.erase(a.begin()+a.size()-1);
			a.erase(a.begin());
			c.erase(c.begin()+c.size()-1);
			c.erase(c.begin());
			
		}
	}
	cout<<ans;
	}