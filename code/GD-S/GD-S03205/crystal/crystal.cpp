#include<bits/stdc++.h>
using namespace std;
const int N=1000009;
long long n,m,a[N];
long long sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	sum[0]=0; int ans=0;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i;
		while(l!=r&&l+1!=r)
		{
			int mid=(l+r)/2;
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m) r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	printf("%d",ans);
	return 0;
}
