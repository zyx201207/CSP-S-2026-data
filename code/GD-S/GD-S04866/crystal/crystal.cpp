#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
int n,m,a[M],sum[M],ans=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	for (int i=1; i<=n; i++)
	{
		int l=1,r=i,res=1;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (abs(sum[i]-sum[mid-1]-(i-mid+1)*a[i])<=m)
			{
				res=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		//cout<<i<<' '<<res<<'\n';
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
