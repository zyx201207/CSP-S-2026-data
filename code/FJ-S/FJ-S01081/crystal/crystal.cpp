#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long n,m;
bool che(int x)
{
	long long cnt=0;
	for(int i=1;i<x;i++)
	{
		cnt+=(a[x]-a[i]);
	}
	if(cnt>m)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int erfen()
{
	int l=1,r=n;
	int mid;
	while(l<r)
	{
		mid=(l+r)/2+1;
		if(che(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	return l;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<erfen();
	return 0;
}
