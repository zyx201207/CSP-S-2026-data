#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],i,j,ma,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1),ma=0,j=1;
	for(i=1;i<=n;i++){
		while(ma>m&&j<i)ma-=(a[i]-a[j]),j++;
		ans=max(ans,i-j+1),ma+=(i-j+1)*(a[i+1]-a[i]);
	}
	printf("%lld",ans);
	return 0;
}
