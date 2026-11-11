#include<bits/stdc++.h>
using namespace std;
struct node
{
	int v,w;
	operator < (const node x) const
	{
		return x.w<w;
	};
};
vector<node>e[305];
int a[500005],k[500005],dp[1005][1005],dis[305][305];
vector<int>x[500005];
vector<int>y[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q,xza=1,xzb=1;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		if(k[i]>2)	
			xza=0;
		for(int j=1;j<=k[i];j++)
		{
			int xx=0,yy=0;
			cin>>xx>>yy;
			x[i].push_back(xx);
			y[i].push_back(yy);
		}
	}
	if(xza||(c>=7&&c<=11))
	{
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			dp[x[i][1]][x[i][0]]=y[i][0]+y[i][1];
			dp[x[i][0]][x[i][1]]=y[i][1]+y[i][0];
		}
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				for(int kk=1;kk<=m;kk++)
					if(kk!=i&&i!=j&&j!=kk)
						dp[i][kk]=min(dp[i][j]+dp[j][kk],dp[i][kk]);
		while(q--)
		{
			int qd,zd;
			cin>>qd>>zd;
			cout<<dp[qd][zd]+a[qd]+a[zd]<<endl;
		}
		return 0;
	}
	/*if(c<=6)
	{
		for(int i=1;i<=n;i++)
			for(int j=0;j<k[i];j++)
				for(int kk=0;kk<k[i];kk++)
					if(j!=kk)
					{
						e[x[i][j]].push_back({x[i][kk],y[i][j]+y[i][kk]});
						e[x[i][kk]].push_back({x[i][j],y[i][j]+y[i][kk]});
					}
		while(q--)
		{
			memset(dis,0x3f,sizeof(dis));
			int st,en;
			cin>>st>>en;
			priority_queue<node>q;
			q.push({st,0});
			while(!q.empty())
			{
				node u=q.top();
				q.pop();
				for(auto v:e[u])
					if(dis[u][v]>dis)
					{
						q.push(v);
					}
			}
		}
	}*/
	return 0;
}

