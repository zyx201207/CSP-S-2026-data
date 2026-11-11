#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
bool check(long long x)
{
	long long cnt=0;
	for(int i=1;i<=x;i++)
	{
		cnt+=a[x]-a[i];
	}
	if(cnt<=m)
	{
		return 1;
	}
	for(int i=x+1;i<=n;i++)
	{
		cnt-=a[i-1]-a[i-x];
		cnt+=(a[i]-a[i-1])*(x-1);
		if(cnt<=m)
		{
			return 1;
		}
	}
	return 0;
}
void ef()
{
	long long l=1,r=n,mid,ans=1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=max(ans,mid);
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
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
	ef();
	return 0;
}
