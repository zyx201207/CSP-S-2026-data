#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int C,N,M,D,Q;
	cin>>C>>N>>M>>D>>Q;
	vector<ll> ent(M+1,0);
	for(int i=1;i<=M;i++){
		cin>>ent[i];
	}
	
	vector<vector<ll>> sw(N+1,vector<ll>(M+1,1e13));
	vector<vector<ll>> dp(M+1,vector<ll>(M+1,1e13));
	vector<vector<int>> sam(M+1,vector<int>(M+1,0));
	vector<vector<vector<int>>> lin(M+1,vector<vector<int>>(M+1,vector<int>(2,0)));
	for(int i=1;i<=N;i++){
		int K;
		cin>>K;
		int v=0;
		for(int j=1;j<=K;j++){
			int u,w;
			cin>>u>>w;
			sw[i][u]=w;
			sam[v][u]=i;
			sam[u][v]=i;
			lin[u][v][0]=i;
			lin[u][v][1]=i;
			lin[v][u][0]=i;
			lin[v][u][1]=i;
			v=u;
		}
	}
	
	for(int i=1;i<=M;i++){
		dp[i][i]=0;
	}
	
	for(int i=1;i<=M;i++){
		for(int j=1;j<=M;j++){
			for(int k=1;k<=M;k++){
				if(i==j) continue;
				if(sam[i][k]==sam[k][j] && sam[j][k]!=0){sam[i][j]=sam[i][k];sam[j][i]=sam[i][k];}
				if(sam[i][j]!=0){
					dp[i][j]=0;
					dp[j][i]=0;
					lin[i][j][0]=sam[i][j];
					lin[i][j][1]=sam[i][j];
					lin[j][i][0]=sam[i][j];
					lin[j][i][1]=sam[i][j];
				}
				else if(dp[i][k]+dp[k][j]+sw[lin[i][k][1]][k]+sw[lin[k][j][0]][k]<dp[i][j]){
					dp[i][j]=dp[i][k]+dp[k][j]+sw[lin[i][k][1]][k]+sw[lin[k][j][0]][k];
					dp[j][i]=dp[i][k]+dp[k][j]+sw[lin[i][k][1]][k]+sw[lin[k][j][0]][k];
					lin[i][j][0]=lin[i][k][0];
					lin[i][j][1]=lin[k][j][1];
					lin[j][i][0]=lin[k][i][0];
					lin[j][i][1]=lin[j][k][1];
				}
			}
		}
	}
	
	while(Q--){
		int x,y;
		cin>>x>>y;
		cout<<ent[x]+ent[y]+min(sw[lin[x][y][1]][x]+sw[lin[x][y][0]][y],sw[lin[x][y][0]][x]+sw[lin[x][y][1]][y])+dp[x][y]<<endl;
	}
	
	return 0;
}
