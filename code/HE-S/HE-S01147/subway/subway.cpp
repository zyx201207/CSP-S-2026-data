#include<bits/stdc++.h>
using namespace std;
long long a[1005][1005],n,m,d,q,c,w[1005],k,dp[1005][1005];
long long t[50005][1005],s[50005][1005],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=1005;i++){
		for(int j=1;j<=1005;j++){
			if(i==j) dp[j][j]=0;
			else dp[i][j]=1e9;
		}
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>s[j][i]>>t[j][i];
    }
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				dp[s[j][i]][s[k][i]]=t[j][i]+t[k][i];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				if(dp[i][k]!=1e9&&dp[k][j]!=1e9)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+dp[x][y]<<'\n';
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
}
