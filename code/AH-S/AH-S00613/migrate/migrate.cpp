#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long x[5005],dp[1005][1005],ans[1005][1005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==13||c==14){
			
		}
		memset(dp,0x3f,sizeof(dp));
		memset(ans,0,sizeof(ans));
		for(long long i=1;i<=n;i++){
			dp[i][i]=-1;
			ans[i][i]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					dp[i][i]=-1;
					ans[i][i]=1;
				}if(abs(x[i]-x[j])<=d){
					dp[i][j]=dp[j][i]=min(dp[i][j],(long long int)0);
					ans[i][j]=1;
				}
			}
		}
		for(long long k=1;k<=n;k++){
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<=n;j++){
					if(i==j||i==k||k==j)continue;
					if(dp[i][j]==dp[i][k]+dp[k][j]+1){
						//cout<<i<<' '<<j<<' '<<dp[i][j]<<'1'<<endl;
						
						ans[i][j]+=ans[i][k]*ans[k][j];
					}
					if(dp[i][j]>dp[i][k]+dp[k][j]+1){
						dp[i][j]=dp[j][i]=dp[i][k]+dp[k][j]+1;
						//cout<<i<<' '<<j<<' '<<dp[i][j]<<'2'<<endl;
						ans[i][j]=ans[i][k]*ans[k][j];
					}
				}
			}
		}
		//for(long long i=1;i<=n;i++){
			//for(long long j=1;j<=n;j++){
				//cout<<dp[i][j]<<ans[i][j]<<' ';
	//		}
		//	cout<<endl;
		//}
		long long cnt=0;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(ans[i][j]==2){
					cnt++;
				}
			}
		}
		cout<<cnt/2<<endl;
	}
    return 0;
}
