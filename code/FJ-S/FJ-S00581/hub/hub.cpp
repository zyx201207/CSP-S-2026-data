#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
 	freopen("crystal.in","r",stdin); 
 	freopen("crystal.out","w",stdout);
	ll n,m,maxx=0,y=1;
	cin>>n>>m;
	vector<ll>v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
		if(v[i]!=i+1)y=0;
	}
	if(y==1)
	{
		maxx=1;
		for(ll j=n-2;j;j--)
		{
			if(v[n-1]-v[j]>m)break;
			else maxx++,m-=v[n-1]-v[j]; 
		}
		maxx=min(maxx,n);
		cout<<maxx;
		return 0;
	}
	sort(v.begin(),v.end());
	ll o=v[1]-v[0],f=1;
	for(ll i=1;i<n-1;i++)
	{
		if(v[i+1]-v[i]!=o)
		{
			f=0;
			break;
		}
	}
	if(f==1)
	{
		maxx=1;
		for(ll j=n-2;j;j--)
		{
			if(v[n-1]-v[j]>m)break;
			else maxx++,m-=v[n-1]-v[j]; 
		}
		cout<<maxx;
		return 0;
	}
	for(ll i=1;i<n;i++)
	{
		ll d=m,p=1;
		for(ll j=i-1;j>=0;j--)
		{
			if(v[i]-v[j]>d)break;
			else p++,d-=v[i]-v[j]; 
		}
		maxx=max(maxx,p);
	} 
	cout<<maxx;
	return 0;
}
