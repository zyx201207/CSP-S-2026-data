#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans=1;
int a[N],sum[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		if((a[i]!=a[i+1]&&i<n)||i==n)
		{
			int l=1,r=i,res=1;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(a[i]*mid-(sum[i]-sum[i-mid])<=m)
				{
					l=mid+1;
					res=mid;
				}
				else r=mid-1;
			}
			ans=max(ans,res);
		}
	}
	cout<<ans;
	return 0;
}