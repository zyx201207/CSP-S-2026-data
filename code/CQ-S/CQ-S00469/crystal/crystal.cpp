#include<bits/stdc++.h>
using namespace std;
const long long N=5*1e5+5;
long long n,m,a[N],sum[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long l=1,r=i-1,res=i;
		while(l<=r){
			long long mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m){
				res=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/ 
