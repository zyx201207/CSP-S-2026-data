#include<bits/stdc++.h>
using namespace std;
int t,c,n,d,a[5005],dp[5005][5005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		//由i为起点到j结束的路径有多少
		dp[1][2]=1;
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				if(v==u+1){
					dp[u][v]=1;
					//cout<<0<<' '<<u<<' '<<v<<' '<<u+1<<"     ";
				}
				//遍历所有的dp[u][v]寻找次数最少的，如果有次数最少的重复的dp就取值
				else{
					int minx=1e9,sum=0;
					for(int m=u+1;m<=v;m++){
						if(a[u]+d<a[v]){
							if(dp[u][m]<minx){
								if(a[m]+d>=a[v])
								minx=dp[u][m],sum=1;
								//cout<<dp[u][m]<<' '<<u<<' '<<m<<endl;
							}
							else if(dp[u][m]==minx)sum++;
						}
						else {
							sum=1;
							break;
						}
					}
					dp[u][v]=sum;
					//cout<<dp[u][m]<<' '<<u<<' '<<m<<endl;
											
					
				}
			}
			for(int u=1;u<=n;u++)for(int v=u+1;v<=n;v++)if(dp[u][v]==2)ans++;
		}	
		cout<<ans<<endl;
//		for(int u=1;u<=n;u++){
//			for(int v=u+1;v<=n;v++)cout<<dp[u][v]<<' ';
//			cout<<endl;
//		}
	}
}