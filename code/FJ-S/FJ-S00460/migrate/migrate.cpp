#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10;

long long cc,t;
long long n,d,a[N],c[N],cnt,flag1;

int main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	scanf("%lld%lld",&cc,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);cnt=0;
		memset(c,0,sizeof(c));
		for(long long i=1;i<=n;++i){
			scanf("%lld",&a[i]);
			if((i>=3)&&(a[i]-a[i-1]!=a[i-1]-a[i-2]))flag1=0;
		}
		if(d>=a[n]-a[1]){
			printf("0\n");
			continue;
		}
		if(flag1){
			if(d==2)printf("%lld\n",n-3);
			else printf("0\n");
			continue;
		}
		for(long long i=1;i<=n-1;++i){
			if(a[i+1]-a[i]<=d&&(i==n?1:a[i+2]-a[i]>d)&&(i==1?1:a[i+1]-a[i-1]>d)){
				long long dx=a[i+1]-a[i];
				for(long long j=i+1;j<=n;++j)
					a[j]=a[j+1]-dx;
				--n,++c[i];
			}
		}
		for(long long i=1;i<=n-3;++i){
			if(a[i+3]-a[i]>d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d)cnt+=(c[i]+1)*(c[i+1]+1)*(c[i+2]+1)*(c[i+3]+1);
		}
		printf("%lld\n",cnt);
	}


	return 0;
}

