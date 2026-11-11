#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,sum[10000001],z[27];
string a,x,y,m;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>sum[i]>>a;
		for(ll j=1;j<=sum[i];j++)
		{
			x+=a;
		}
	}
	for(ll i=x.size()-1;i>=0;i--)
	{
		y[n-i]=x[i];
	}
	if(x==y)
	{
		cout<<0;
	}
	else
	{
		for(ll i=0;i<=x.size()-1;i++)
		{
			if(i==x.size()/2+x.size()%2)
			{
				continue;
			}
			m+=x[i];
		}
		for(ll i=0;i<=25;i++)
		{
			for(ll j=0;j<=m.size();j++)
			{
				z[int(m[i])-'A']++;
			}
		}
		ll maxn=-1;
		for(ll i=0;i<=25;i++)
		{
			if(maxn<z[i])
			{
			    maxn=max(maxn,z[i]);
		    }
		}
		ll sum=0;
		for(ll i=0;i<=m.size()-1;i++)
		{
			if(y[i]!=char(maxn+'A'))
			{
				sum++;
			}
		}
		cout<<sum;
	}
} 
