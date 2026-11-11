#include<bits/stdc++.h>
using namespace std;
const long long RP=LONG_LONG_MAX;
long long n,m,a[512345],ans,s;
void pd(){
	long long l=a[1],r=a[n]+m,mid,sum,cnt=0;
	while(l<r){
		sum=m,mid=l+(r-l)/2,cnt=0;
		for(long long i=upper_bound(a+1,a+n+1,mid)-a;i>=1;i--)
			if(mid>=a[i])
				sum-=(mid-a[i]),cnt+=(sum>=0);
		ans=max(ans,cnt);
		if(sum<0) r=mid;
		else l=mid+1;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld ",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	pd();
	printf("%lld",ans);
	return 0;
}
