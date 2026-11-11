#include<bits/stdc++.h>
using namespace std;
#define int long long
long long n,m,a[500010],l=1,p=1,sum,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	sum=m;
	while(l<n&&sum>=l*(a[l+1]-a[l])){
		sum-=l*(a[l+1]-a[l]);
		l++;
	}
	ans=l;
	for(int i=l+1;i<=n;i++){
		sum-=(i-p)*(a[i]-a[i-1]);
		while(p<i&&sum<0){
			sum+=a[i]-a[p];
			p++;
		}
		ans=max(ans,i-p+1);
	}
	printf("%lld",ans);
	return 0;
}
