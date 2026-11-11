#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;cin>>n;
	ll a;string b,sum,w;
	ll ans=0,j=0,cnt=0;
	while(n--)
	{
		cin>>a>>b;
		for(ll i=1;i<a;i++)
		{
			if(i==1&&cnt==0)
			{
				sum=b;
			}
			sum+=b;
		}
		cnt++;
	}
	for(ll i=sum.size()-1;i>=0;i--)
	{
		w[j]=sum[i];
		j++;
	}
	for(ll i=0;i<sum.size();i++)
	{
		if(w[i]!=sum[i])
		{
			sum[i]=w[i];
			ans++;
		}
	}
	cout<<ans;
}
/*
2
2 a
2 a
*/
