#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N];
long long sum[N];
long long ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	sum[0]=0;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		long long l=1,r=i;
		long long tmp=0;
		while(l<r)
		{
			long long mid=(l+r)>>1;
			long long need=(i-mid)*a[i]-(sum[i-1]-sum[mid-1]);
			if(need>m) l=mid+1;
			else r=mid;
		}
		tmp=i-l+1;
		ans=max(tmp,ans);
	}
	cout<<ans;
	return 0;
}
