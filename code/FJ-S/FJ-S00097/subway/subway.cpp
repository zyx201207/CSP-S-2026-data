#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],k[505],a[501][100001],t[501][100001],x,y,dp[10005][10005];
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
			dp[i][j]=t[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+t[x][x]+w[y]+t[x][y]<<'\n';
	}
	return 0;
}
