#include<bits/stdc++.h>
#define longlong long long
//#define longlong __int128_t
#define ll (longlong)
namespace NOTLE{
	void NOTLE(){
		std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
		return;
	}
	void NO_TLE(){
//		std::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
		return;
	}
}
using namespace std;
bool frein=false,freout=false,refrein=false;
longlong n,m,a[500010ll],sum[500010ll],ans=1ll;
signed main(){
	NOTLE::NO_TLE();//samples:4
	freopen("crystal.in","r",stdin),frein=true;
	freopen("crystal.out","w",stdout),freout=true;
	refrein=(frein and not(freout));
	scanf("%lld%lld",&n,&m);
	if(refrein)	printf("%lld %lld\n",n,m);
	for(longlong i=1ll;i<=n;i++){
		scanf("%lld",&a[i]);
		if(refrein)	printf("%lld ",a[i]);
	}
	sort(a+1ll,a+1ll+n);
	if(refrein)	printf("\n");
	for(longlong i=1ll;i<=n;i++)	sum[i]=sum[i-1]+a[i];
	for(longlong i=1ll;i<=n;i++){
		longlong l=1ll,r=i,mid=((l+r)>>1ll);
		while(l<r){
			longlong x=(a[i]*(i-mid+1ll))-sum[i];
			if(x+sum[mid-1ll]<=m)	r=mid-1ll;
			if(x+sum[mid-1ll]>m)	l=mid+1ll;
			mid=((l+r)>>1ll);
		}
		while(0ll<mid and a[i]*(i-mid+1ll)-sum[i]+sum[mid-1ll]<=m)	mid--;
		while(mid<i and m<a[i]*(i-mid+1ll)-sum[i]+sum[mid-1ll])	mid++;
		ans=max(ans,(i-mid+1ll));
	}
	printf("%lld\n",ans);
	return 0;
}
