#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010];
bool ff(long long x)
{
	for(long long i=x;i<=n;i++)
	{
		if(x*a[i]-(s[i]-s[i-x])<=m)
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	long long l=1,r=n;
	while(l<r)
	{
		long long mid=(l+r+1)/2;
		if(ff(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
