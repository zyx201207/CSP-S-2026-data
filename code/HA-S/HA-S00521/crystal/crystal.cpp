#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
bool check(int x)
{
	int nw=0;
	for(int i=1;i<x;i++)	nw+=a[x]-a[i];
	if(nw<=m)	return true;
	for(int i=x+1;i<=n;i++)
	{
		nw-=a[i-1]-a[i-x];
		nw+=(a[i]-a[i-1])*x;
		if(nw<=m)	return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
