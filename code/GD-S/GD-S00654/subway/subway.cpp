#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int c,n,m,d,q,w[N];
vector<int>tr[N],a[N];
int dp[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
//	if(c>=12&&c<=19)
//	{
//		
//	}
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		tr[i].resize(k);
		a[i].resize(k);
		for(int j=0;j<k;j++)
			cin>>a[i][j]>>tr[i][j];
		for(int j=0;j<k;j++)
			for(int l=j+1;l<k;l++)
				dp[a[i][j]][a[i][l]]=dp[a[i][l]][a[i][j]]=min(dp[a[i][l]][a[i][j]],tr[i][l]+tr[i][j]);
	}
	for(int i=1;i<=m;i++)dp[i][i]=0;
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=i+1;j<=m;j++)
				if(i!=j)
					dp[i][j]=dp[j][i]=min(dp[i][j],dp[i][k]+dp[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dp[x][y]<<endl;
	}
	return 0;
}
