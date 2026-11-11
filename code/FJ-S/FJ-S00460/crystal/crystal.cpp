#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;

long long n,m,ans,minx;
long long a[N],b[N],flag1;

int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	flag1=1;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;++i){
		scanf("%lld",&a[i]);minx=min(a[i],minx);
		if((i>=3)&&(a[i]-a[i-1]!=a[i-1]-a[i-2]))flag1=0;
	}
	
	if(flag1){
		long long ans=(long long)((-1.0+sqrt(1+8*n))/2.0);
		printf("%lld",ans+1);
		return 0;
	}
	
	sort(a+1,a+n+1);
	
	for(long long i=1;i<=n;++i){
		a[i]-=minx;
		b[i]=b[i-1]+a[i];
	}
	
	for(long long len=n;len>=1;--len){
		for(long long i=1;i+len-1<=n;++i){
			long long j=i+len-1;
			long long s=a[j]*len-(b[j]-b[i-1]);
			if(s<=m){
				printf("%lld",len);
				return 0;
			}
		}
	}

	return 0;
}
