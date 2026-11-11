#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y;
int w[505],k[505],f[505][505],t[505][505],a[1005][1005],dp[10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int j=1;j<=m;j++){
		cin>>w[j];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>f[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				a[i][j]=0x3fffffff;
				a[i][i]=0x3fffffff;	
			}
			dp[i]=0x3fffffff;
		}
		dp[x]=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=k[i];j++){
				a[i][f[i][j]]=t[i][j];
				a[f[i][j]][i]=t[i][j];
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=k[i];j++){
				dp[i]=min(dp[j]+a[j][i],dp[i]);
			}
		}
		cout<<w[x]+w[y]+dp[y]<<endl;
	}
	return 0;
}
