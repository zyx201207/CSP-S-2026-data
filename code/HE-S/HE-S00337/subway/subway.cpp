#include<bits/stdc++.h>
using namespace std;

const int N=610;
int c,n,m,d,q;
int dp[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f,sizeof dp);
	cin>>c>>n>>m>>d>>q;
	int n1=n+2*m;
	for(int i=1;i<=n1;i++){
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		dp[i][i+m]=x;
		dp[i+m][i]=x;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			dp[i+2*m][x]=y;
			dp[x][i+2*m]=y;
		}
	}
	for(int k=1;k<=n1;k++){
		for(int i=1;i<=n1;i++){
			for(int j=1;j<=n1;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
//	for(int i=1;i<=n1;i++){
//		for(int j=1;j<=n1;j++){
//			cout<<dp[i][j]<<" "; 
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dp[x+m][y+m]<<endl;
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
其实就是按照他的输入构建一张图 
*/
