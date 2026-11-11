#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
long long a[maxn];
long long sum[maxn];
int n;
long long m;
long long get(int x)
{
	int l=1,r=x,best=-1,mid;
	long long dis;
	while(l<=r)
	{
		mid=(l+r)>>1;
		dis=1LL*(x-mid)*a[x];
		if(sum[x-1]-sum[mid-1]+m>=dis)
		{
			best=x-mid+1;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return best;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(sum[i-1]-sum[i-2]+m<a[i]&&i>1) continue;
		long long ans2=get(i);
		ans=max(ans,ans2);
	}
	cout<<ans;
	return 0;
}
