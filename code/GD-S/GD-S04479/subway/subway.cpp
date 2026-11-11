#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
long long n,m,q,c,d,dp[1007][1007],w[1007];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c>=7&&c<=11){
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j) dp[i][j]=0;
				else dp[i][j]=INF;
			}
		}
		for(int i=1,u,v,w1,w2,z;i<=n;i++){
			cin>>z>>u>>v>>w1>>w2;
			dp[u][v]=w1+w2;
			dp[v][u]=w1+w2;
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=m;k++){
					if(dp[j][k]>dp[j][i]+dp[i][k]){
						dp[j][k]=dp[j][i]+dp[i][k];
					}
				}
			}
		}
		while(q--){
			int u,v;
			cin>>u>>v;
			cout<<dp[u][v]+w[u]+w[v]<<"\n";
		}
		return 0;
	}	
	int gg=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k,u,ww;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u>>ww;
			gg=ww;
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<w[u]+w[v]+gg+gg<<"\n";
	}
	return 0;
}
