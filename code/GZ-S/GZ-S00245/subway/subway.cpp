//GZ-S00245 华麟 杨承锦 
#include<bits/stdc++.h>
using namespace std;
#define to first
#define w second
const int inf=1e9+7;
int c,n,m,d,q;
//也就是一共有m个地铁站 n类线路 
int wtee[100005];
int wt[100005];
int dp[5005][5005];
//vector<pair<int,int>>g[50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>wtee[i];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			dp[i][j]=inf;//floyd csh
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		/*
		if(k==2){
			int u,v,s1,s2;
			cin>>u>>s1>>v>>s2;
			//vector[u].push_back({v,wt[u]+wt[v]});
			//vector[v].push_back({u,wt[u]+wt[v]});
			dp[u][v]=s1+s2;
			dp[v][u]=s1+s2;
		}
		else{int bb;cin>>bb>>bb;}
		*/
		
		int lasts,lastv;
		for(int j=1;j<=k;j++){
	        int u,s;
	        cin>>u>>s;
	        if(j>=2){
	        
			dp[u][lastv]=s+lasts;
			dp[lastv][u]=s+lasts;
		    }
	        lasts=s;
	        lastv=u;
	        
		}
		
		
	}//woqu sihushi floyd
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				//if(mp.count(j)==1)dp[i][j];
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]+wtee[x]+wtee[y]<<"\n";
	}
	return 0;
}/*

0 3 7 20 2
 8 3 6 1 7 2 9
 3 1 4 2 5 5 100
 3 2 6 3 1 7 2
 4 3 2 5 100 4 6 6 7
 1 6
 2 3
*/
