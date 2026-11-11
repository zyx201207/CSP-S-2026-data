#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,a[2000001],f[2000001],zzz;
long long h[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		zzz=0;
		memset(f,0,sizeof(f));
		memset(h,0,sizeof(h));
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(long long u=n;u>=1;u--){
			f[u]=0;
			for(long long i=u+1;i<=n;i++){
				long long mc=999999999;
				for(long long o=1;o<n;o++){
					if(a[i]-a[i-o]<=d){
						mc=min(mc,f[i-o]+1);	
					}else{
						break;
					}
				}
				if(mc==999999999){
					mc=0;
				}
				long long kll=0;
				if(h[i]== h[i-1] and f[i-1]== f[i-2] and f[i-1]==h[i-1]){
					if(f[i-3]==0 ){
						kll=h[i];
					}	
				}
				f[i]=mc;
				if(kll)
				if(f[i]==kll+1){
					zzz++;
				}
				h[i]=f[i];	
			}
		}
		printf("%lld\n",zzz);
	}
	return 0;
}
