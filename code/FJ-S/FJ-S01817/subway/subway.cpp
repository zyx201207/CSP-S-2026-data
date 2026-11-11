#include <bits/stdc++.h>
using namespace std;
int C,n,m,d,p,x,y,k[501],o=1,s,c;
long long a[501],dp[501][501];
long long ans;
void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int _=1;_<=n;_++){
				dp[i][j]=min(dp[i][j],dp[i][_]+dp[_][j]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>m>>n>>d>>p;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(dp[i][j]==0 && i!=j)dp[i][j]=10000000000000000;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>k[i];
		cin>>x>>y>>s>>c;
		dp[x][s]=y+c;
		dp[s][x]=y+c;
	}
	floyd();
	for(int i=1;i<=p;i++){
		cin>>x>>y;
		ans=a[x]+a[y]+dp[x][y];
		cout<<ans<<"\n";
	}
	return 0;
}
