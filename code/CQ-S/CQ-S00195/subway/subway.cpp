#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[200005],x,y,dp[352][352][352],l[352][352];
signed main(){
	//printf
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(c<=6||n+m<=350){
		for(int i=1;i<=350;i++) for(int j=1;j<=350;j++) l[i][j] = 1e17;
		int k;
		for(int i=1;i<=n;i++){
			cin>>k;
			while(k--){
				cin>>x>>y;
				l[x][m+i] = l[m+i][x] = y;
			}
		}
		for(int i=1;i<=m+n;i++) for(int j=1;j<=m+n;j++) dp[0][i][j] = l[i][j];
		for(int k=1;k<=m+n;k++){
			for(int i=1;i<=m+n;i++){
				for(int j=1;j<=m+n;j++){
					dp[k][i][j] = min(dp[k-1][i][j],dp[k-1][i][k]+dp[k-1][k][j]);
				}
			}
		}
		while(q--){
			cin>>x>>y;
			cout<<dp[m+n][x][y]+w[x]+w[y]<<endl;
		}
	}
	return 0;
}

