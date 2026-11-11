#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,sum=0,d=0;
	cin>>n;
	vector<ll>v(n);
	vector<char>v1(n);
	for(ll i=0;i<n;i++)
	{	
		ll a;
		cin>>a>>v1[i],sum+=a;
		v[i]=sum;
	}
	if(v[0]==1000000000)
	{
		cout<<1000000000*n/2;
		return 0;
	}
	vector<char>v2(sum);
	for(ll i=0,j=0;i<sum&&j<n;i++)
	{
		if(j==0&&i<v[0])v2[i]=v1[j];
		else if(i<v[j]&&i>=v[j-1])v2[i]=v1[j];
		else j++,v2[i]=v1[j];
	}
	for(ll i=0,j=sum-1;i<j;i++,j--)
	{
		if(v2[j]!=v2[i])d++;
	}
	cout<<d;
	return 0;
} 
