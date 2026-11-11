#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[2000005],dp[2000005],fa[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
       scanf("%lld%lld",&n,&m);	
       for(long long i=1;i<=n;i++){
       	   scanf("%lld",&a[i]);
	   }
	   ans=0;
	   for(long long p=1;p<=n;p++){
	   	   for(long long i=1;i<=n;i++){
	   		    dp[i]=0x3f3f3f3f3f3f3f3f;
       	        fa[i]=0;
		   }
	   fa[p]=1;
	   dp[p]=0;
	   for(long long i=p+1;i<=n;i++){
	   	    for(long long j=i-1;j>=p;j--){
	   	   	    if(a[i]-a[j]<=m){
	   	   	    	if(dp[i]==dp[j]+1){
	   	   	    		fa[i]+=fa[j];
					}else if(dp[i]>dp[j]+1){
						dp[i]=dp[j]+1;
						fa[i]=fa[j];
					}
				}else{
					break;
				}
		    }
	    }
	        for(long long i=p;i<=n;i++){
	    	if(fa[i]==2) ans++;
		    }
	   }
	   printf("%lld\n",ans);
	}
	return 0;
}

