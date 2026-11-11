#include <bits/stdc++.h>
using namespace std;
const int N=1e9+5;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,d,q;
	int w[N];
	int t[N][N],dp[N][N];
	cin>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
			cin>>w[i];
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++){
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>dp[i][j];
			dp[i][j]=max(dp[i][j],w[i]+t[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<dp[i][j];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
