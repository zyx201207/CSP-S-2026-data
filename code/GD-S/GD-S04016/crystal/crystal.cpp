#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],sum[500100],ans;
long long check(long long x,long long y){
	if (a[y]*(y-x+1)-(sum[y]-sum[x-1])<=m)return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for (long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for (long long i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<r){
			long long mid=l+(r-l)/2;
			if (check(mid,i)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}
