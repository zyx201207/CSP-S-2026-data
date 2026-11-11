#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[50010],k[510];
long long a[1010][1010],t[100][1010];
long long dp[1010][10010];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=m;i++)dp[i][i]=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			dp[a[i][j]][a[j][j]]=min(dp[i][j],t[i][j]+t[j][i]);
			
		}
	}for(int k=1;k<=n;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=dp[j][i]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]<<"\n";
		
	} 
	return 0;
}

