#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k,f;
int ans;
int a[505];
int b[505];
int w[505];
int dp[1005][1005];
void floyd(){
	for(int i=1;i<=m;i++){
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if((i==k)||(j==k))continue;
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}/*for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}*/
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>b[j];
			if(b[j]!=b[j-1]&&j>1){
				f=1;
			}
		}for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				if(j==l)continue;
				dp[a[j]][a[l]]=b[l]+b[j];
			}
		}
	}
	floyd();
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		ans=dp[u][v]+w[u]+w[v];
		cout<<ans<<endl;
	}
	return 0;
}
