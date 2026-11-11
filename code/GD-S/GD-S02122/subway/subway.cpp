#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
int w[M];
int a[510],t[510];
long long dp[2000][2000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)
		cin>>w[i];
	for(int i=1; i<=n; i++){
		int k;
		cin>>k;
		for(int j=1; j<=k; j++){
			cin>>a[j]>>t[j];
		}
	}
	dp[1][1]=t[1];
	for(int i=1; i<=q; i++){
		int x,y;
		cin>>x>>y;
		for(int K=1; K<=n; K++)
			for(int I=1; I<=n; I++)
				for(int J=1; J<=n; J++)
					dp[I][J]=min(dp[I][J],dp[I][K]+dp[K][J]);
		cout<<dp[x][y]<<endl;
	}
	return 0;
}
