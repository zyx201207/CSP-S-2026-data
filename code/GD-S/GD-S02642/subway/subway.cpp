#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int c,n,m,d,q,w[1005],k,l,r,dp[1005][1005],a[1005][1005],t[1005][1005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++) dp[i][i]=t[i][i];
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+t[k][k+1]);
			}
		}
	}
	while(q--){
		cin>>l>>r;
		cout<<dp[l][r]+w[l]+w[r]<<'\n';
	} 
	return 0;
}

