#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1000005;
long long n,a[MAXN],s,l=1,ans=0,k,sum[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(long long r=1;r<=n;r++){
		while(l<r and a[r]*(r-l+1)-(sum[r]-sum[l-1])>k)l++;
		ans=max(ans,r-l+1);
	}
	printf("%lld",ans);
	return 0;
} 
