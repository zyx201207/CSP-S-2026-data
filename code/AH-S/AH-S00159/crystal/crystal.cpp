#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long n,m,maxs,mins=LONG_LONG_MAX;
bool check(int x)
{
	long long t=m;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>x) break;
		t-=(x-a[i]);
	}
	return t>=0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		maxs=max(maxs,a[i]);
		mins=min(mins,a[i]);
	}
	if(m>=1e9)
	{
		long long t=0;
		for(int i=1;i<=n;i++)
		{
			if(t+i<=m) t+=i;
			else
			{
				cout<<i;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	long long l=mins,r=maxs,mid,ans;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>ans) break;
		cnt++;
	}
	cout<<cnt;
}
