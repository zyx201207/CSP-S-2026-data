#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[600000],ans=0,l,r,m;
bool check(int x)
{
	int ps=0;
	for(int i=2;i<=n;i++)
	{
	    if(i<=x)
		  ps+=(i-1)*(a[i]-a[i-1]);
		else
		{
		  ps-=(a[i-1]-a[i-x]);
		  ps+=(x-1)*(a[i]-a[i-1]);
		}
		if(i>=x&&ps<=m)
		  return 1;
	}
    return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+1+n);
	l=1;r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		  l=mid+1;
		else
		  r=mid-1;
	}
	l--;
	cout<<l;
	return 0;
}

