#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[1005];
long long k[1005];
long long dp[1005][1005];
long long a[1005][1005];
long long t[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dp,0x3f,sizeof(dp));
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(long long j=1;j<=k[i];j++){
			for(long long k1=1;k1<=k[i];k1++){
				dp[a[i][j]][a[i][k1]]=min(dp[a[i][j]][a[i][k1]],t[i][a[i][k1]]+t[i][a[i][j]]);
			}
		}
	}
	for(long long i=1;i<=m;i++){
		dp[i][i]=0;
	}
	for(long long k1=1;k1<=m;k1++){
		for(long long j=1;j<=m;j++){
			for(long long i=1;i<=m;i++){
				dp[i][j]=min(dp[i][j],dp[i][k1]+dp[k1][j]);
			}
		}
	}
	while(q--){
		long long st,en;
		cin>>st>>en;
		cout<<dp[st][en]+w[st]+w[en]<<'\n';
	}
	return 0;
}

