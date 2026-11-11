#include<bits/stdc++.h>
using namespace std;
int c;
int n;
int m;
int d;
int q;
int w[500051];
int k[511];
int a[1005][1005];
int t[1005][1005];
int p;
int x;
int y;
int jg[505];
int fi[305][305][305];
int dp[305][305][305];//head,from x,to y
int dp2[305][305]; 
//i should let dp be 4 level or need 2 dp
int ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c;
	cin>>n;
	cin>>m;
	cin>>d;
	cin>>q;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j){
					dp[k][i][j]=t[k][i];
					dp2[i][j]=0;
				}
				else{
					dp[k][i][j]=99999999;
					dp2[i][j]=99999999;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			jg[j]=a[i][j];
			cin>>t[i][j];
		}
		for(int ii=1;ii<=k[i];ii++){
			for(int jj=1;jj<=k[i];jj++){
				if(ii!=jj){
					fi[i][jg[ii]][jg[jj]]=1;
					fi[i][jg[jj]][jg[ii]]=1;
				}
			}
		}
		for(int ii=1;ii<=m;ii++){
			for(int jj=1;jj<=m;jj++){
				if(ii!=jj){
					dp[i][ii][jj]=t[i][ii]+t[i][jj];
					dp[i][jj][ii]=t[i][ii]+t[i][jj];
				}
			}
		}
	}
	for(int kp=1;kp<=m;kp++){//i to kp,kp to j
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i!=j){
					for(int kk=1;kk<=n;kk++){//zhuan xian ii turn to kk,kk turn to jj
						for(int ii=1;ii<=n;ii++){
							for(int jj=1;jj<=n;jj++){
								if(fi[ii][i][kp]==1&&fi[jj][j][kp]==1){
									dp2[i][j]=min(dp2[i][j],dp2[i][kp]+dp2[kp][j]);
									dp[kp][i][j]=min(dp[kp][i][j],dp[kp][i][kp]+dp[kp][kp][j]);
//									dp[kp][i][j]=min(dp[kp][i][j],dp[kp][i][kk]+dp[kp][kk][j]+dp2[i][j]);
								}
							}
						}
					}
				}
			}
		}
	}
	while(q--){
		cin>>x;
		cin>>y;
		ans=INT_MAX;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans=min(ans,dp[i][x][y]+dp[j][x][y]);//i in,j out
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0; 
}
