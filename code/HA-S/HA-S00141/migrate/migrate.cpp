#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2200000];
long long cha[2200000];
long long dp[2500][2500];
long long sm[2500][2500];
vector<long long> ls[2200000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&d);
		for(long long i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			ls[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=0;
				sm[i][j]=0;
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(abs(a[j]-a[i])<=d){
					ls[i].push_back(j);
					ls[j].push_back(i);
					dp[j][i]=1;
				}else{
					dp[j][i]=-1;
				}
			}
		}
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i-1;j>=1;j--){
				if(dp[i][j]==1) sm[i][j]=1;
				else sm[i][j]=0;
				for(long long k=j+1;k<i;k++){
					if((dp[i][k]+dp[k][j]<dp[i][j] || dp[i][j]==-1) && dp[i][k]!=-1 && dp[k][j]!=-1){
						dp[i][j]=dp[i][k]+dp[k][j];
						sm[i][j]=sm[i][k]*sm[k][j];
					}else if(dp[i][k]+dp[k][j]==dp[i][j]){
						sm[i][j]+=sm[i][k]*sm[k][j];
					}
				}
				if(sm[i][j]==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
}
