#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
int ans;
long long m,a[N],sum[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ans=1;
	for (int i=1;i<=n;i++)
	{
		int l=1,r=i,res=0x3f3f3f3f;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m) res=mid,r=mid-1;
			else l=mid+1;
			ans=max(ans,i-res+1);
		}
	}
	cout<<ans;
	return 0;
}
