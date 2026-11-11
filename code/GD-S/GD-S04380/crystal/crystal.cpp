#include <bits/stdc++.h>
using namespace std;
long long n,m,cnt=0,ans=1;
long long a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	/*for(long long i=1;i<=n;i++){
		printf("%lld\n",a[i]);
	}*/
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long l=1,r=1;
	while(r<=n)
	{
		if(cnt<=m){
			r++;
			cnt=a[r]*(r-l)-(sum[r-1]-sum[l-1]);
			if(cnt<=m){
				ans=max(ans,r-l+1);
			}
		}
		else if(cnt>m){
			cnt=cnt-(a[r]-a[l]);
			l++;
			if(cnt<=m){
				ans=max(ans,r-l+1);
			}
		}
	}
	printf("%lld",ans);
	
	
	return 0;
} 
