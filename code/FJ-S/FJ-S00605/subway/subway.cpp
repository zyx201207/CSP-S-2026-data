#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,t[502][500002];
long long w[500002],dp[502][502],ans;
vector<int>ln[500002];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>c;
		while(c--){
			cin>>x;
			cin>>t[i][x];
			ln[x].push_back(i);
		}
		for(int j=1;j<=n;j++)dp[i][j]=2000000000000000000;
		dp[i][i]=0;
	}
	for(int k=1;k<=m;k++)
		for(int i=0;i<ln[k].size();i++)
			for(int j=0;j<ln[k].size();j++)dp[ln[k][i]][ln[k][j]]=min(dp[ln[k][i]][ln[k][j]],1ll*t[ln[k][i]][k]+1ll*t[ln[k][j]][k]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	while(q--){
		cin>>x>>y;
		ans=2000000000000000000;
		for(int i=0;i<ln[x].size();i++)
			for(int j=0;j<ln[y].size();j++)ans=min(ans,dp[ln[x][i]][ln[y][j]]+1ll*t[ln[x][i]][x]+1ll*t[ln[y][j]][y]);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;	
}
