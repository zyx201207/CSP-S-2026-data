#include<bits/stdc++.h>
#define int long long 
using namespace std;
int dp[2500][2500];
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1; i<=t; i++){
		int n,k;
		cin>>n>>k;
		memset(dp,0,sizeof(dp));
		for(int j=1; j<=n-1; j++){
			int u,v;
			cin>>u>>v;
			dp[u][v]=1;
		}
		for(int k=1; k<=n; k++)
			for(int ii=1; ii<=n; ii++)
				for(int j=1; j<=n; j++)
					dp[ii][j]=min(dp[ii][j],dp[ii][k]+dp[k][j]);
		cout<<dp[n][k]+1<<endl;
	}
	return 0;
}
