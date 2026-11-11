#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005];
bool check(int mid){
	for(int i=mid; i<=n; i++){
		int st=i-mid+1;
		if(sum[i]-sum[st-1]+m>=a[i]*mid) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1; i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%lld",ans);
	return 0;
}
