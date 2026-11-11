#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e4+10;
ll id,n,m,d,q,i,j,k;
ll a[N],c[510][N][2],cnt[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>id>>n>>m>>d>>q;
	for(i=1;i<=m;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		cin>>cnt[i];
		for(j=1;j<=cnt[i];j++) cin>>c[i][j][0]>>c[i][j][1];
	}
	ll dp[m+5][m+5];
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++) dp[i][j]=1e18;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=cnt[i];j++){
			for(k=j+1;k<=cnt[i];k++){
				dp[c[i][j][0]][c[i][k][0]]=min(dp[c[i][j][0]][c[i][k][0]],c[i][j][1]+c[i][k][1]);
				dp[c[i][k][0]][c[i][j][0]]=min(dp[c[i][k][0]][c[i][j][0]],c[i][j][1]+c[i][k][1]);
			}
		}
	}
	for(k=1;k<=m;k++){
		for(i=1;i<=m;i++){
			for(j=1;j<=m;j++){
				dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
			}
		}
	}
	ll x,y;
	while(q--){
		cin>>x>>y;
		cout<<dp[x][y]+a[x]+a[y]<<endl;
	}
	return 0;
}
