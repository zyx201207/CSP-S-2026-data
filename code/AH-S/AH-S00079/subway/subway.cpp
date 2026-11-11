#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,k;
struct node{
	int x,w;
}a,b;
int x,y;
int f[500010];
vector<node> v[500010];
int dp[510][510]={0};
signed main()
{
    std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(int)v[i].size();j++)
		{
			for(int k=j+1;k<(int)v[i].size();k++)
			{
				a=v[i][j];
				b=v[i][k];
				dp[a.x][b.x]=dp[b.x][a.x]=min(dp[a.x][b.x],a.w+b.w);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		dp[i][i]=0;
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		int mina=1e18;
		for(int l=0;l<(int)v[x].size();l++)
		{
			for(int r=0;r<(int)v[y].size();r++)
			{
				a=v[x][l];
				b=v[y][r];
				mina=min(mina,a.w+dp[a.x][b.x]+b.w);
			}
		}	
		cout<<mina+f[x]+f[y]<<endl;
	}
	return 0;
}
