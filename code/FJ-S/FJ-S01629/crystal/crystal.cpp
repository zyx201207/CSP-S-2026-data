#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=1;
int a[500005];
int sum[500005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i =1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i =1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i =1;i<=n;i++)
	{
		int l=ans,r=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[i]*mid-(sum[i]-sum[i-mid])<=m)
			{
				l=mid+1;
				ans=max(ans,mid);
			}
			else r=mid-1;
		}
//		for(int j =ans;j<=i;j++)
//		{
//			if(a[i]*j-(sum[i]-sum[i-j])<=m)
//			{
//				ans=max(ans,j);
//			}
//		}
	}
	cout<<ans;
	return 0;
 } 
