#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long n,m,ans=INT_MIN;
bool check(long long x,long long y)
{
	long long sum=0;
	for(long long i=y;i<=x;i++)/////////////////////
	{
		sum+=a[x]-a[i];
	}
	if(sum<=m)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	a[0]=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(long long i=1;i<=n;i++)
	{
		long long l=i,r=n;
		while(l<=r)
		{
			long long mid=l+(r-l)/2;
			if(check(mid,i))
			{
				ans=max(mid-i,ans);
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
	}
	cout<<++ans;
	return 0;
} 
