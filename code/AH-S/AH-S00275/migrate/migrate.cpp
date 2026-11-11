#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int c,t;
long long x[N];		
bool dis[N][N];//i能否到达j
long long dp[N][N];//plans
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		long long n,d;
		scanf("%lld%lld",&n,&d);
		//for(int i=1;i<=N;i++){
			//for(int j=1;j<=N;j++){
				//dis[i][j]=0;
				//dp[i][j]=0;
			//}
		//}
		memset(dis,0,sizeof(dis));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=i-1;j>=1;j--){
				if(abs(x[i]-x[j])<=d&&i!=j){
					dis[i][j]=1;
					dis[j][i]=1;
				}else{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				cout<<dis[i][j]<<' ';
				for(int k=i+1;k<=j-1;k++){
					if(dis[i][k]&&dis[k][j]&&!(dis[i][j])){
						dp[i][j]++;
					}
				}
			}
//			cout<<endl;
		}
		long long cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
//				cout<<dp[i][j]<<' ';
				if(dp[i][j]==2)cnt++;
			}
//			cout<<endl;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
