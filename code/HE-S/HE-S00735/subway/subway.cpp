#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long dp[5010][5010];
long long z[3000],t[3000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=(n+2)*m;i++){
		for(long long j=1;j<=(n+2)*m;j++){
			dp[i][j]=0x3f3f3f3f;
		}
	}
	for(long long i=1;i<=m;i++){
		long long w;
		cin>>w;
		dp[i][i+m]=w;
		dp[i+m][i]=w;
	}
	for(long long i=2;i<=n+1;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>z[j]>>t[j];
			dp[z[j]+i*m][z[j]+m]=t[j];
			dp[z[j]+m][z[j]+i*m]=t[j];
		}
		for(long long j=2;j<=k;j++){
			dp[z[j]+i*m][z[j-1]+i*m]=0;
			dp[z[j-1]+i*m][z[j]+i*m]=0;
		}
	}
	for(long long k=1;k<=(n+2)*m;k++){
		for(long long i=1;i<=(n+2)*m;i++){
			for(long long j=1;j<=(n+2)*m;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(long long i=1;i<=q;i++){
		long long v,u;
		cin>>v>>u;
		cout<<dp[v][u]<<endl;
	}
	return 0;
} 
