#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N],res=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i-1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			int num=i-1-mid+1;
			if(a[i]*num-(sum[i-1]-sum[mid-1])<=m)
			{
				res=max(res,num+1);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	cout<<res;
	return 0;
}