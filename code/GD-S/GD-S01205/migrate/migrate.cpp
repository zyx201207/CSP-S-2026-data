#include<bits/stdc++.h>
using namespace std;
long long c,t,d,n,h[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	//if(c==11||c==12){
		while(t--){
			scanf("%lld%lld",&n,&d);
			printf("%lld\n",n);
			for(long long i=1;i<=n;i++){
				scanf("%lld",&h[i]);
			}
			long long delta=h[n]-h[n-1];
			printf("%lld %lld\n",delta,d);
			if(d>=2*delta){
				
				long long t=d/delta;if(d%delta==0)t++;
				if(n-t-1>0)
					ans=n-t-1;	
				else ans=0;		
			}else{
				ans=0;
			}
			printf("%lld\n",ans);
		}	
//	}
	
	return 0;
}

