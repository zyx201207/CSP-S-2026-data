#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int c,n,m,d,q,w[N],dp[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,127,sizeof(dp));
	dp[0][0]=1;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;i<=x;j++){
			int a,t;
			cin>>a>>t;
			dp[i+m][a]=dp[a][i+m]=t;
			cout<<dp[i+m][a]<<" "<<dp[a][i+m]<<endl;
		}
	}
	m=m+n;
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dp[i][k]!=2139062143&&dp[k][j]!=2139062143)dp[i][j]=min(dp[i][j],min(dp[i][k],dp[k][j]));
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
