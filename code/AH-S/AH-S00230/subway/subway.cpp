#include<bits/stdc++.h>
using namespace std;
long long c,a[5005],n,m,s,e,q,d,f[5005][5005],p[5005][5005],dp[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
		cin>>a[i];	
	memset(f,0x3f,sizeof(f));
	memset(p,0x3f,sizeof(p));
	memset(dp,0x3f,sizeof(dp));
	for (int i=1;i<=n;i++){
		int len;
		cin>>len;
		for (int j=1;j<=len;j++){
			int x,y;
			cin>>x>>y;
			f[x][i]=y;
			p[i][x]=y;
		}
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=m;i++)
			for (int j=1;j<=m;j++){
				if (f[i][k]+p[k][j]<dp[i][j])
					dp[i][j]=f[i][k]+p[k][j];
			}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++){
			dp[i][j]=min(dp[i][j],dp[j][i]);
		}
	for (int k=1;k<=m;k++)
		for (int i=1;i<=m;i++)
			for (int j=1;j<=m;j++){
				if (dp[i][k]+dp[k][j]<dp[i][j])
					dp[i][j]=dp[i][k]+dp[k][j];
			}
	while (q--){
		cin>>s>>e;
		cout<<a[s]+a[e]+dp[s][e]<<"\n";
	}
	return 0; 
} 
