#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=1;
	while(r<=n&&l<=n){
		while(r<=n&&(abs((unsigned long long)a[r]*(r-l+1)-sum[r]+sum[l-1])<=m))r++;
		ans=max(ans,r-l);
		l++;
	}
	printf("%lld\n",ans);
	return 0;
}
/*5 8
-3 -1 2 2 7

*/
