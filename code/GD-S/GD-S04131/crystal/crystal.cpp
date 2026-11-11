#include<bits/stdc++.h>
using namespace std;
long long tsq;
long long n,m;
long long a[500001];
long long sum[500001];
int mx=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)/2;
			long long need=(i-mid+1)*a[i]-(sum[i]-sum[mid-1]);
			if(need<=m) {
				mx=max(mx,i-mid+1);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	printf("%d",mx);
}
