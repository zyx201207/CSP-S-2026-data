#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],q[500005];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(q[i]-q[i-x]+m>=x*a[i])
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		q[i]=q[i-1]+a[i];
	}
	int l=1,r=n+1,mid=(l+r)>>1;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
