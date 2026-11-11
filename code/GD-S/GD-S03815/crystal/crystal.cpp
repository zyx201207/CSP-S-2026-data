#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=5e5+10;
int n,m,a[N],sum[N],tot;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,ans;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m) ans=mid,r=mid-1;
			else l=mid+1;
		}
		tot=max(tot,i-ans+1);
	}
	cout<<tot;
	return 0;
}
