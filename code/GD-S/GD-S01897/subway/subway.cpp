#include<bits/stdc++.h>
using namespace std;
int w[550000],dp[2205][2205];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	int n,m,q;
	scanf("%d%d%d%d%d",&n,&n,&m,&q,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int a,v;
			scanf("%d%d",&a,&v);
			dp[m+i][a]=v;
			dp[a][m+i]=v;
		}
	}
	for(int i=1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++){
			for(int k=1;k<=m+n;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				dp[j][i]=dp[i][j];
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d",dp[x][y]+w[x]+w[y]);
		cout<<endl;
	}
	return 0;
}
