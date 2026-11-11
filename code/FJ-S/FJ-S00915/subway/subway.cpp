#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXM=(int)(5e3),MAXN=505;//请检查数组大小
int w[MAXM],k[MAXN],a[MAXN][MAXM],t[MAXN][MAXM];
int dp[1100][1100];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//请开freopen
	memset(dp,0x3f,sizeof dp);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++)
		{
			for(int l=1;l<=k[i];l++)
			{
				dp[a[i][j]][a[i][l]]=t[i][j]+t[i][l];
			}
		}
	}
	for(int kk=1;kk<=m;kk++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][kk]+dp[kk][j]);
			}
		}
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<dp[l][r]+w[l]+w[r]<<endl;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
