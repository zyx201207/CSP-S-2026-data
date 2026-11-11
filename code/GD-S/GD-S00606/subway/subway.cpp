#include<bits/stdc++.h>
using namespace std;
int w[1005],t[505][1005];
long long dp[1005][1005];
int c,n,m,d,q,k,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int v=1;v<=m;v++){
		cin>>w[v];
	}int ai;
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>ai;
			cin>>t[ai][j];
		}
	}for(int i=1;i<m;i++){
		for(int j=1;j<=n;j++){
			if(t[j][i]){
				for(int k=1;k<=m;k++){
					if(i==k)continue;
					if(t[j][k]){
						long long now=t[j][i]+t[j][k];
						if(dp[i][k]==0)dp[i][k]=now;
						else dp[i][k]=min(dp[i][k],now);
					}
				}
			}
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		if(x>y)swap(x,y);
		if(x==y){
			cout<<0<<endl;
			continue;
		}if(dp[x][y]){
			cout<<w[x]+w[y]+dp[x][y]<<endl;
			continue;
		}bool flag=0;
		for(int i=1;i<=m;i++){
			if(i==x||i==y)continue;
			if(dp[x][i]&&dp[y][i]){
				dp[x][y]=dp[x][i]+dp[y][i];
				flag=1;break;
			}
		}if(flag){
			cout<<w[x]+w[y]+dp[x][y]<<endl;
			continue;
		}bool flag2=0;
		for(int i=1;i<=m;i++){
			if(i==x||i==y)continue;
			for(int j=i+1;j<=m;j++){
				if(j==x||j==y)continue;
				if((dp[x][i]&&dp[i][j]&&dp[y][i])){
					dp[x][y]=dp[x][i]+dp[i][j]+dp[y][i];
					flag2=1;break;
				}if((dp[x][j]&&dp[j][i]&&dp[y][i])){
					dp[x][y]=dp[x][j]+dp[j][i]+dp[y][i];
					flag2=1;break;
				}
			}if(flag2)break;
		}if(flag2){
			cout<<w[x]+w[y]+dp[x][y]<<endl;
			continue;
		}
	}
	return 0;
} 
