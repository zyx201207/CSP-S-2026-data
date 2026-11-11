#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long l=1,r=i-1,p=i;
		while(l<=r){
			long long mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)p=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-p+1);
	}
	printf("%lld",ans);
	return 0;
} 
