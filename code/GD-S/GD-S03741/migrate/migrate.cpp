#include<bits/stdc++.h>
using namespace std;
const long long MAXN=2000005;
long long dp[305][305],c,t,a[MAXN],n,d,len[305][305];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		bool ok=0;
		for(long long i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(i>=3){
				if(a[i]-a[i-1]!=a[i-1]-a[i-2])ok=1;
			}
		}
		if(n<=300){
			memset(len,-1,sizeof(len));
			for(long long i=1;i<n;i++){
				for(long long j=i+1;j<=n;j++){
					long long now=i,ci=0;
					while(now!=j){
						bool ok=0;
						for(long long k=j;k>now;k--){
							if(a[k]-a[now]<=d){
								ci++;
								now=k;
								ok=1;
								break;
							}
						}
						if(!ok)break;
					}
					if(now!=j)len[i][j]=-1;
					else len[i][j]=ci;
				}
			}
			memset(dp,0,sizeof(dp));
			long long ans=0;
			for(long long j=n;j>=2;j--){
				for(long long i=j-1;i>=1;i--){
					if(len[i][j]<2){
						if(len[i][j]==1){
							dp[i][j]=1;
						}
						continue;
					}
					for(long long k=i+1;k<j;k++){
						if(len[i][k]!=1)break;
						if(len[k][j]==-1)continue;
						if(len[k][j]+1!=len[i][j])continue;
						dp[i][j]+=dp[k][j];
					}
					if(dp[i][j]==2)ans++;
				}
			}
			printf("%lld\n",ans);
		}else if(!ok){
			long long maxx=a[2]-a[1],ans=0;
			maxx=d/maxx;
			for(long long i=1;i<=n;i++){
				if(i+2*maxx-1<=n)ans++;
			}
			if(maxx<=1){
				printf("0\n");
				continue;
			}
			printf("%lld\n",ans);
		}else printf("0\n");
	}
	return 0;
} 
/*
0 1
10 3
-10 -7 -4 -3 -2 -1 0 1 4 7
*/
