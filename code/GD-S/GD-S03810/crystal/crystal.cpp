#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],sum[N];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++) {
		int l=0,r=i;
		while(l+1<r) {
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)
				r=mid;
			else l=mid;
		}
		if(r<i) ans=max(i-r+1,ans); 
	}
	printf("%lld\n",ans);
	return 0;
}
