#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a,t,x[500005],y[500005],dp[505][505],dpx[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;dp[i][a]=t;
			dpx[i][a]=dp[i][a]+dp[j][j];
		}
 }
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j)continue;
				if(dpx[i][k]!=0&&dpx[k][j]!=0){
					if(dpx[i][j]!=0)dpx[i][j]=min(dpx[i][j],dpx[i][k]+dpx[k][j]);
					else dpx[i][j]=dpx[i][k]+dpx[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++)cout<<dpx[x[i]][y[i]]+w[x[i]]+w[y[i]]<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)
			cout<<dpx[i][j]<<' ';
		cout<<endl;
	}cout<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)
			cout<<dp[i][j]<<' ';
		cout<<endl;
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
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
