#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 600;
const int M = 2e4+100;
int n,m,c,d,q;
int t[N][M];
int w[M],sb,cs;
int dp[1005][1005];
int k,x[N][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dp[i][j] = INT_MAX;
		}
		dp[i][i] = 0;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x[i][j];
			cin>>t[i][x[i][j]];
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				dp[x[i][j]][x[i][l]] = min(dp[x[i][j]][x[i][l]],t[i][x[i][j]]+t[i][x[i][l]]);
				dp[x[i][l]][x[i][j]] = dp[x[i][j]][x[i][l]];
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>sb>>cs;
		cout<<dp[sb][cs] + w[sb] + w[cs]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
