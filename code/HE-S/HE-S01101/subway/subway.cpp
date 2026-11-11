#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int c,n,m,d,q;

int v[N][N],nei[N],dp[N][N];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>nei[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int w,vr;
			cin>>w>>vr;
			v[k][w]=vr;
			v[w][k]=vr;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=1e9;
		}
	}
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[i][j] = min(v[i][k] + v[k][j] + 2*nei[k],dp[i][j]);
			}
		}
	}
	
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]<<endl;
	}
	return 0;
}
