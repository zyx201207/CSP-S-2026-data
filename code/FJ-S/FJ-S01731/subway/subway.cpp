#include<bits/stdc++.h>
using namespace std;
int n,m,d,q,c,k,a,t;
const int N=1e4;
int dp[N][N];
int s[N][N];
int sum;
int de;
int dfs(int x,int y)
{
	if ((y-x)==1)
	{
		return dp[x][y];
	}
	for (int i=x+1;i<y;i++)
	{
		if((dp[x][i]!=0)&&(dp[i][y]!=0))
		{
			dp[x][y]=min(dp[x][y],dp[x][i]+dp[i][y]);
		}
	}
	return dp[x][y];
}
int main()
{
	freopen("sub2.txt","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m+3];
	int xr,yr;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			cin>>a>>t;
			s[j][a]=t;
			for (int h=1;h<=j;h++)
			{
				if (dp[h][j]==0)
				{
					dp[h][j]=s[j][h]+t;
				}
				else
				{
					dp[h][j]=min(dp[h][j],(s[j][h]+t));
				}
			}
		}
		
	}
    int p=dfs(1,n);
    int qq=99999,ww=99999;
	for (int i=1;i<=q;i++)
	{
		cin>>xr>>yr;
		de=dp[xr][yr];
		for (int j=1;j<=n;j++)
		{
			if (s[j][xr]!=0)
			{
			
			    qq=min(qq,s[j][xr]);
			}
			if (s[j][yr]!=0)
			{
			
			    ww=min(ww,s[j][yr]);
			}
		}
		sum=de+w[xr]+w[yr]+ww+qq;
		cout<<sum<<endl;
	}
	return 0;
}
