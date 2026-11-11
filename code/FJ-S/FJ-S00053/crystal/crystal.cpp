#include<bits/stdc++.h>
using namespace std;
const int N=500005;
#define ll long long
ll a[N];
ll sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(sum[i]-sum[mid-1]>=a[i]*(i-mid+1)-m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%d\n",ans);
	return 0;
}

/*
5 5
1 2 4 8 9
*/
