#include <bits/stdc++.h>
using namespace std;
#define int long long
long long n,m;
long long a[500010],sum[500010];
bool chk(int x){
	for(int i=x;i<=n;++i){
		if(a[i]*x-(sum[i]-sum[i-x])<=m){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(chk(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	printf("%lld",ans);
	return 0;
}
