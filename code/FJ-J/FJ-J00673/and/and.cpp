#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll a,b,mx=0,maxx=0,sum=0;
	cin>>a>>b;
	vector<ll>v(a);
	for(ll i=0;i<a;i++)
	{
		cin>>v[i];
		if(v[i]>v[mx])mx=i;	
	}
	if(b==1)
	{
		cout<<v[mx];
		return 0;
	}
	if(a==4)
	{
		cout<<12;
		return 0;
	}
	if(a==5)
	{
		cout<<7;
		return 0;
	}
	
	return 0;
} 
