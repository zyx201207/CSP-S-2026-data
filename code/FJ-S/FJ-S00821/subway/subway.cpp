#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[5005],dp[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp,0x3f,sizeof(dp));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int a[5005]={},t[5005]={},x;
		cin>>x;
		for(int i=1;i<=x;i++){
			cin>>a[i]>>t[i];
			for(int j=1;j<=i;j++){
				dp[a[i]][a[j]]=min(dp[i][j],t[i]+t[j]);
				dp[a[j]][a[i]]=min(dp[j][i],t[i]+t[j]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int lbs,lla;
		cout<<dp[lbs][lla]+w[lbs]+w[lla]<<'\n';
	}
	return 0;
}
