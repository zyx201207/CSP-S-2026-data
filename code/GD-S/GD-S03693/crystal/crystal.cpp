#include <bits/stdc++.h>
#define int long long
#define MAXN 500005
using namespace std;
int n,a[MAXN],m,sum[MAXN],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,re=i;
		while(l<=r){
			int mid=l+r>>1;
			int s=sum[i]-sum[mid-1];
			if((i-mid+1)*a[i]-s<=m)r=mid-1,re=mid;
			else l=mid+1;
		}
		ans=max(ans,i-re+1);
	}
	printf("%lld\n",ans);
	return 0;
}
