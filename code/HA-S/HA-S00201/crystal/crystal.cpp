#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],maxn,s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m<=INT_MAX)
	{
		for(ll i=a[n]+1;i>=1;i--)
		{
			ll j,sum=0;
			ll l=1,r=n;
			while(l<=r)
			{
				j=(l+r)/2;
				if(a[j]<=i)
				{
					l=j+1;
				}
				else
				{
					r=j-1;
				}
			}
			j--;
			ll x=j;
			for(;j>=1;j--)
			{
				sum+=i-a[j];
				if(sum>m)
				{
					break;
				}
			}
			maxn=max(x-j,maxn);
		}
		cout<<maxn;
		return 0;
	}
	for(ll i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(ll i=n;i>=1;i--)
	{
		ll x=s[i]-s[1]+a[1];
		if(x<=m)
		{
			cout<<i;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
/*
        A
       A A       C C C C C
      A  A      C
     A   A     C
    A    A     C
   A A A A     C
  A      A     C
 A       A      C
A        A       C C C C C
*/