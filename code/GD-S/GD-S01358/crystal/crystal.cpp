#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;
int n,m,a[N];
ll sum[N];
bool check(int x)
{
	ll num=0;
	for(int i=1;i<=x;i++)
	{
		ll k=sum[x]-sum[i];
		num+=k;
	}
	if(num<=m)
	{
		return true;
	}
	for(int i=x+1;i<=n;i++)
	{
		num-=(sum[i-1]-sum[i-x]);
		num+=(sum[i]-sum[i-1])*(x-1);
		if(num<=m)
		{
			return true;
		}
	}
	return false;
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
	for(int i=2;i<=n;i++)
	{
		sum[i]=a[i]-a[i-1]+sum[i-1];
	}
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
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

