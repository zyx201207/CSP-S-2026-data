#include<bits/stdc++.h>
using namespace std;
int bianhao,tielushu,zhantaishu,luguo_max;
int jihuashu;
int k_t[500005],a[501][501],t[501][501];
int graph[501][501],dp[501][501];
const int INF=0x3f3f3f3f;
int main(){
	freopen("subway.in","w",stdin);
	freopen("subway.out","r",stdout);
	cin>>bianhao>>tielushu>>zhantaishu>>luguo_max>>jihuashu;
	for(int i=1;i<=zhantaishu;i++){
		cin>>k_t[i];
	}
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			dp[i][j]=INF;
		}
	}
	for(int i=1;i<=tielushu;i++){
		int k;
		cin>>k;
		int x;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			if(j==1){
				x=a[i][j];
				graph[a[i][j]][a[i][j]]=t[i][j];
			}
			if(j>=2){
				graph[x][a[i][j]]=t[i][j];
				graph[a[i][j]][x]=t[i][j];
			}
		}
	}
	for(int i=1;i<=zhantaishu;i++){
		for(int j=1;j<=zhantaishu;j++){
			if(i!=j&&graph[i][j]){
				dp[i][j]=graph[i][j]+graph[i][i];
			}
		}
	}
	for(int k=1;k<=zhantaishu;k++){
		for(int i=1;i<=zhantaishu;i++){
			for(int j=1;j<=zhantaishu;j++){
				if(i==k||k==j) continue;
				if(dp[i][k]!=INF&&dp[k][j]!=INF){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=jihuashu;i++){
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]+k_t[x]+k_t[y]<<endl;
	}
	return 0;
}

