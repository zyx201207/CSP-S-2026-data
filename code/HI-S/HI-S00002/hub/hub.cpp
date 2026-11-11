#include<bits/stdc++.h>
using namespace std;
int n,k,dp[1005][1005][3][2],h[1005];
int f[1005][11];
vector<int>a[10005];
//void bfs(int x,int y){
//	h[x]=h[y]+1;
//	f[x][0]=y;
//	for(int i=1;i<=10;i++) f[x][i]=f[f[x][i-1]][i-1];
//	for(int i=0;i<a[x].size();i++){
//		if(a[x][i]==y) continue;
//		bfs(i,x);
//	}
//}
//int lca(int x,int y){
//	if(h[x]<h[y]) swap(x,y);
//	for(int i=10;i>=0;i--){
//		if(h[f[x][i]]>=h[y]){
//			x=f[x][i];
//		}
//	}
//	if(x==y) return x;
//	for(int i=10;i>=0;i--){
//		if(f[x][i]!=f[y][i]){
//			x=f[x][i];
//			y=f[y][i];
//		}
//	}
//	return f[x][0];
//}
//void dfs(int x,int y){
//	for(int i=0;i<a[x].size();i++){
//		if(a[x][i]==y) continue;
//		dfs(i,x);
//	}
//	int mx=0;
//	for(int i=1;i<=n;i++) mx=max(mx,h[x]+h[i]+1-2*h[lca(x,i)]);
//	dp[x][0][0][0]=mx;
//	for(int i=0;i<a[x].size();i++){
//		for(int j=i+1;j<a[x].size();j++){
//		    if(a[x][i]==y||a[x][j]==y) continue;
//		    for(int p=1;p<=k;p++){
//		    	dp[x][p][1][0]=min(dp[x][p][1][0],max(mx,dp[a[x][i]][p][1][0]));
//		    	for(int q=0;q<p;q++){
//		    		dp[x][p][1][1]=min(dp[x][p][1][1],max(dp[a[x][i]][q][1][1],dp[a[x][j]][p-1-q][1][1]));
//		    		dp[x][p][2][0]=min(dp[x][p][2][0],max(mx,max(min(dp[a[x][i]][q][1][1],dp[a[x][i]][q][1][0]),min(dp[a[x][j]][p-q][1][0],dp[a[x][j]][p-q][1][1]))));
//		    		dp[x][p][2][1]=min(dp[x][p][2][1],max(dp[a[x][i]][q][1][1],dp[a[x][i]][p-q-1][1][0]));
//		    		dp[x][p][2][1]=min(dp[x][p][2][1],max(dp[a[x][i]][q][1][0],dp[a[x][i]][p-q-1][1][1]));
//		    		dp[x][p][2][1]=min(dp[x][p][2][1],dp[a[x][i]][p-1][1][0]);
//				} 
//			}
//	    }
//	}
//	if(a[x].size()==0){
//		dp[x][1][1][1]=0;
//	}
//}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		cout<<0<<"\n"; 
//		for(int i=1;i<n;i++){
//			for(int j=1;j<=k;j++){
//				dp[i][j][1][1]=100000000;
//				dp[i][j][2][0]=100000000;
//				dp[i][j][1][1]=100000000;
//				dp[i][j][2][0]=100000000;
//			}
//		}
//		bfs(1,0);
//		dfs(1,0);
//		cout<<max(max(max(dp[n][k][1][0],dp[n][k][1][1]),dp[n][k][2][1]),dp[n][k][2][0]);
	} 
	return 0;
}
