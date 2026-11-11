#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+10;

int c,T;
int n;
long long ans;
long long d;
long long a[N];
long long dp[N],cnt[N];
long long sum[N];

void solvea(){
	
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
    	bool isa = true;
    	scanf("%d%lld",&n,&d);
    	for(int i = 1;i<=n;i++){
    		scanf("%lld",&a[i]);
    		//check A
    		if(i>2){
    			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
    				isa = false;
				}
			}
			if(i>1){
				sum[i] = sum[i-1]+a[i]-a[i-1];
			}
		}
//		if(isa){
//			solvea();
//		}
        ans = 0;
        for(int i = 1;i<=n;i++){
        	for(int j = i+1;j<=n;j++){
        		memset(dp,0x3f,sizeof(dp));
        		memset(cnt,0x3f,sizeof(cnt));
        		dp[i] = 0;
        		cnt[i] = 1;
        		for(int k = i+1;k<=j;k++){
        		    int l;
        		    for(l = i;l<k;l++){
        		    	if(sum[k]-sum[l]<=d){
        		    		if(dp[k] == 0x3f3f3f3f || dp[l]+1<dp[k]){
        		    			dp[k] = dp[l]+1;
        		    			cnt[k] = 1;
							}else if(dp[l]+1 == dp[k]){
								cnt[k]++;
							}
						}
					}
				}
				if(cnt[j] == 2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}                                                               
