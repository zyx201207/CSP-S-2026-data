#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
struct oo{
	int v,w;
}way[5010],stop[510];
int c,n,m,d,q;
int dp[5510][5510];
int w[200010];
int a[201011];
int t[201010];
int x[201010];
int y[201010];
signed main(){
	freopen("subway.in","w",stdin);
	freopen("subway.out","r",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a,t;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int k=1;k<=n;k++){
//			for(int j=1;j<=n;j++){
//				dp[i][j]=min(dp[i][k]+dp[j][k],dp[i][j]);
//			}
//		}
//	}
	return 0;
}
