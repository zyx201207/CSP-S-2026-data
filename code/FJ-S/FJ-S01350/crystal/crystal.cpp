#include<bits/stdc++.h>
#define int long long
#define mid ((l+r)>>1)
using namespace std;
const int N=1000000;
int n,m,a[N],sum[N],ans=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,res=i;
		while(l<=r)
		{
			if(((i-mid+1)*a[i]-(sum[i]-sum[mid-1]))<=m)
			{
				res=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
