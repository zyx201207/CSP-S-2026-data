#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[2005][2005],t[2005][2005];
int w[125254];
int dp[2005][2005],k[2005];
void floyd(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int l=1;l<=m;l++){
				dp[i][j]=min(dp[i][j],dp[i][l]+dp[l][j]);
			}
		}
	}
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			//g[a[i][j]].push_back({g[a[i][l],a]});
		}
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				dp[a[i][j]][a[i][l]]=t[i][j]+t[i][l];
				dp[a[i][l]][a[i][j]]=t[i][j]+t[i][l];
			}
		}
	}
	floyd();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
