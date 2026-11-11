#include<bits/stdc++.h>
using namespace std;
#define int long long
int n=0,a[114514],b[1145][1145],xxx[114514],dp[1145][1145],num[114514],xian[1145][1145],len[114514],vis[1145][1145],p=0,cnt=0;
struct xy
{
	int x;
};
vector<int> bian[1145];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>p>>cnt>>cnt;
	for(int i=1;i<=p;i++)
	{
		cin>>num[i];
	}
	for(int i=1;i<=1140;i++)
	{
		for(int j=1;j<=1140;j++)
		{
			dp[i][j]=114514000;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>len[i];
		int xx=0;
		for(int j=1;j<=len[i];j++)
		{
			int x=0,y=0;
			cin>>x>>y;
			bian[i].push_back(x);
			b[i][x]=y;
			xian[i][x]=1;
		}
		for(int j=0;j<bian[i].size();j++)
		{
			for(int k=0;k<bian[i].size();k++)
			{
				dp[bian[i][j]][bian[i][k]]=0;
				vis[bian[i][j]][bian[i][k]]=i;
				vis[bian[i][k]][bian[i][j]]=i;
			}
		}
	}
	for(int k=1;k<=p;k++)
	{
		for(int i=1;i<=p;i++)
		{
			for(int j=1;j<=p;j++)
			{
				if(dp[i][j]>dp[i][k]+dp[k][j]+b[vis[i][k]][k]+b[k][vis[k][j]])
				{
					xxx[i]=vis[i][k];
					xxx[j]=vis[k][j];
				}
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+ b[vis[i][k]][k] + b[k][vis[k][j]]+b[xxx[i]][i]+b[xxx[j]][j]);
			}
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		int x=0,y=0;
		cin>>x>>y;
		if(dp[x][y]==0)
		{
			dp[x][y]=dp[x][y]+b[vis[x][y]][x]+b[vis[x][y]][y];
		}
		cout<<dp[x][y]+num[x]+num[y]<<endl;
	}
}
