#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x[2000005];
ll dp[5005][5005],cnt[5005][5005];//dp为i到j的最短飞行次数，cnt为i到j的最短路径数 
const ll NAF=1e18;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
//	freopen("migrate3.in","r",stdin);
//	freopen("migrate3.out","w",stdout);

	int c,t;
	cin>>c>>t;
	while(t--){
		int n,res=0;ll d;
		cin>>n>>d;
		
		x[2000005]={};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=NAF;
				cnt[i][j]=1;
			}
		}
		dp[1][1]=0;
		
		
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int j=1;j<=n;j++){
			for(int i=j-1;i>=1;i--){//i<j 
				if(x[j]-x[i]<=d){
					dp[i][j]=1;
//					cout<<"dp"<<i<<","<<j<<"->"<<dp[i][j]<<endl;
				}
				else{
					for(int k=i+1;k<j;k++){
						ll ans=dp[i][k]+dp[k][j];
//						cout<<"--dp"<<i<<","<<k<<"+"<<"dp"<<k<<","<<j<<"="<<ans<<endl;
//						cout<<"--dp"<<i<<","<<j<<"="<<dp[i][j]<<endl;
						if(ans>=NAF) continue;
						if(dp[i][j]==ans) cnt[i][j]+=max(cnt[i][k],cnt[k][j]);
						else if (ans<dp[i][j]){
							dp[i][j]=ans;
							cnt[i][j]=1;
						}
//						cout<<"dp"<<i<<","<<j<<"="<<"dp"<<i<<","<<k<<"+"<<"dp"<<k<<","<<j<<"->"<<dp[i][j]<<endl;
						
					}
					if(cnt[i][j]==2) res++;
//					cout<<"!!cnt"<<i<<","<<j<<"->"<<cnt[i][j]<<endl;
//					cout<<endl;
				}
				
			}
		}
		cout<<res<<endl;
	}
	


	return 0;
}
