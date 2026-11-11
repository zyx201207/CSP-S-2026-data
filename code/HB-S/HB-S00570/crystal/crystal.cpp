#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long s[500010];
int check(int x)
{
	for(int i=1;i<=n-x+1;i++)
	{
		long long sum=s[i+x-1]-s[i-1];
		long long cha=x*a[i+x-1]-sum;
		if(cha<=m)
		{
			return 1;
		}
	}
	return -1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	long long l=1,r=n,mid;
	long long ans=0;
	while(l<=r)
	{
		mid=(r-l)/2+l;
		if(check(mid)==1)
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
