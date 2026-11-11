#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[500005],w[500005],a[505][25],t[505][25],r[100005][3],dp[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i][1]>>r[i][2];
	}
	//一条线路 
	if(n==1){
		for(int i=1;i<=k[1];i++){
			for(int j=1;j<=k[1];j++){
				if(i==j){
					continue;
				}
				if(dp[a[1][i]][a[1][j]]!=0){
					continue;
				}
				dp[a[1][i]][a[1][j]]=w[i]+w[j]+t[i][i]+t[i][j];
				dp[a[1][j]][a[1][i]]=dp[a[1][i]][a[1][j]];
			} 
			
		} 
	}
	//两条线路 
	if(n==2){
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=k[1];i++){
			for(int j=1;j<=k[1];j++){
				if(i==j){
					continue;
				}
				if(dp[a[1][i]][a[1][j]]!=0x3f3f3f3f){
					continue;
				}
				dp[a[1][i]][a[1][j]]=min(w[i]+w[j]+t[i][i]+t[i][j],dp[a[1][i]][a[1][j]]);
				dp[a[1][j]][a[1][i]]=dp[a[1][i]][a[1][j]];
			} 	
		} 
		for(int i=1;i<=k[2];i++){
			for(int j=1;j<=k[2];j++){
				if(i==j){
					continue;
				}
				if(dp[a[2][i]][a[2][j]]!=0x3f3f3f3f){
					continue;
				}
				dp[a[2][i]][a[2][j]]=min(dp[a[2][i]][a[2][j]],w[i]+w[j]+t[i][i]+t[i][j]);
				dp[a[2][j]][a[2][i]]=dp[a[2][i]][a[2][j]];
			} 
		} 
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j){
					continue;
				}
				for(int k=1;k<=m;k++){
					if(dp[i][j]==0x3f3f3f3f&&dp[i][k]+dp[k][j]-2*w[k]<dp[i][j]){
						dp[i][j]=dp[i][k]+dp[k][j]-2*w[k];
						dp[j][i]=dp[i][j];
					}
				}
			}
		}
	}
	if(n==3){
	memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=k[1];i++){
			for(int j=1;j<=k[1];j++){
				if(i==j){
					continue;
				}
				if(dp[a[1][i]][a[1][j]]!=0x3f3f3f3f){
					continue;
				}
				dp[a[1][i]][a[1][j]]=min(w[i]+w[j]+t[i][i]+t[i][j],dp[a[1][i]][a[1][j]]);
				dp[a[1][j]][a[1][i]]=dp[a[1][i]][a[1][j]];
			} 	
		} 
		for(int i=1;i<=k[2];i++){
			for(int j=1;j<=k[2];j++){
				if(i==j){
					continue;
				}
				if(dp[a[2][i]][a[2][j]]!=0x3f3f3f3f){
					continue;
				}
				dp[a[2][i]][a[2][j]]=min(dp[a[2][i]][a[2][j]],w[i]+w[j]+t[i][i]+t[i][j]);
				dp[a[2][j]][a[2][i]]=dp[a[2][i]][a[2][j]];
			} 
		} 
		for(int i=1;i<=k[3];i++){
			for(int j=1;j<=k[3];j++){
				if(i==j){
					continue;
				}
				if(dp[a[3][i]][a[3][j]]!=0x3f3f3f3f){
					continue;
				}
				dp[a[3][i]][a[3][j]]=min(dp[a[3][i]][a[3][j]],w[i]+w[j]+t[i][i]+t[i][j]);
				dp[a[3][j]][a[3][i]]=dp[a[3][i]][a[3][j]];
			} 
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j){
					continue;
				}
				for(int k=1;k<=m;k++){
					if(dp[i][j]==0x3f3f3f3f&&dp[i][k]+dp[k][j]-2*w[k]<dp[i][j]){
						dp[i][j]=dp[i][k]+dp[k][j]-2*w[k];
						dp[j][i]=dp[i][j];
					}
				}
			}
		}
	}	
	if(n!=1&&n!=2&&n!=3){
		memset(dp,0x3f,sizeof(dp));
		for(int z=1;z<=n;z++){
			for(int i=1;i<=k[z];i++){
				for(int j=1;j<=k[z];j++){
				if(i==j){
					continue;
				}
				dp[a[z][i]][a[z][j]]=min(w[a[z][i]]+w[a[z][j]]+t[z][a[z][i]]+t[z][a[z][j]],dp[a[z][i]][a[z][j]]);
				dp[a[z][j]][a[z][i]]=dp[a[z][i]][a[z][j]];
				}
			}
		}for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					if(i==j){
						continue;
					}
					if(dp[i][j]==0x3f3f3f3f&&dp[i][k]+dp[k][j]-2*w[k]<dp[i][j]){
						dp[i][j]=dp[i][k]+dp[k][j]-2*w[k];
						dp[j][i]=dp[i][j];
					}
				}
			}
		}
		
	}
	for(int i=1;i<=q;i++){
		cout<<dp[r[i][1]][r[i][2]]<<endl;
	}
	return 0;
}
