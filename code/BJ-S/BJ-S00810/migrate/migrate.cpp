#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
int c,t,n;
long long x[MAXN],d,Graph[MAXN][MAXN],dp[MAXN][MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		memset(dp,0,sizeof(dp));
		memset(Graph,0x3f,sizeof(Graph));
		for(int i=1;i<=n;i++)Graph[i][i]=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d)Graph[j][i]=Graph[i][j]=dp[j][i]=dp[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int u=1;u<=n;u++){
				for(int v=1;v<=n;v++){
					if(Graph[u][v]>Graph[u][i]+Graph[i][v]){
						Graph[u][v]=Graph[u][i]+Graph[i][v];
						dp[u][v]=dp[u][i]*dp[i][v];
					}else if(Graph[u][v]==Graph[u][i]+Graph[i][v])dp[u][v]+=dp[u][i]*dp[i][v];
				}
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)cout<<Graph[i][j]<<" ";
			cout<<endl;
		}*/
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)ans+=(dp[i][j]==2);
		}
		cout<<ans<<endl;
	}
}
