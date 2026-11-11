#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500010],sum[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		ll l=1,r=i-1;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(a[i]*(i-mid)-sum[i-1]+sum[mid-1]<=m)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
