#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum[500005],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=0,r=i-1,s=1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*mid-(sum[i-1]-sum[i-1-mid])<=m)
				s=mid+1,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,s);
	}
	printf("%lld",ans);
	return 0;
}
