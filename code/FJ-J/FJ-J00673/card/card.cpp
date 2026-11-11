#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m,d=0;
	cin>>n>>m;
	vector<ll>v(n);
	vector<ll>v1(n);
	vector<ll>v2(n);
	for(ll i=0;i<n;i++)cin>>v[i];
	for(ll i=0;i<n-1;i++)
	{
		for(ll j=i+1;j<n;j++)if(v[i]==v[j])d=1;
		if(d==1)break;
	}
	if(d==0)
	{
		for(ll i=0;i<m;i++)cout<<n<<" ";
		return 0;
	}
//	for(ll i=0;i<n;i++)
//	{
//		for(ll j=0;j<n;j++)
//		{
//			if(i<=j)v1[i]=1;
//			else v1[i]=0; 
//		} 
//		for(ll j=i;j<n;j++)
//		{
//			
//		}
//	}
	return 0;
} 
