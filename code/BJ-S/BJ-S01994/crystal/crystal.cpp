#include<bits/stdc++.h>
#define ll long long
const ll maxn=5e5+10;
using namespace std;
ll arr[maxn];
ll n,m;
ll status;
ll ans=1;
ll presum[maxn];
FILE *fl;
signed main(){
	fl=freopen("crystal.in","r",stdin);
	fl=freopen("crystal.out","w",stdout);
	status=scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++){
		status=scanf("%lld",arr+i);
	}
	sort(arr+1,arr+1+n);
	for (int i=1;i<=n;i++){
		presum[i]=presum[i-1]+arr[i];
		int l=1,r=i;
		ll tas=1;
		while(l<=r){
			int mid=(l+r)/2;
			ll len=(i-mid+1);
			ll destval=len*arr[i];
			ll tmpsum=presum[i]-presum[mid-1];
			ll require=destval-tmpsum;
			if (require<=m){
				tas=max(tas,len);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		//fprintf(stderr,"(%lld)",tas);
		ans=max(tas,ans);
	}
	printf("%lld",ans);
	return 0;
}
/*
 * password: Oct31==Dec25?
 * answer status:
 * t1 crystal 100
 * t2 subway 60~84
 * t3 migrate 0~24
 * all:160~208
*/
