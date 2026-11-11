#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,l=1,a[N],sum[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=2;i<=n;i++){	
		while(a[i]*(i-l+1)-sum[i]+sum[l-1]>m) l++;
		ans=max(ans,i-l+1);
	}
	if(ans==1) printf("0");
	else printf("%lld",ans);
	return 0;
}
