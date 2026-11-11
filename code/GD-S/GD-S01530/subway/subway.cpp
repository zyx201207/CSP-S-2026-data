#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,xws;
long long dp[505],vis[505],w[5000005],sc[505][505];
long long zj[505][505];
priority_queue<pair<long long,int> > q;
vector<long long> vec[6000005],wec[6000005];
vector<long long> xd[505],xt[505]; 
void dijkstra(int qd)
{
	memset(dp,0x3f,sizeof(dp));
	memset(vis,0,sizeof(vis));
	dp[qd]=0;
	q.push({0,qd});
	while(q.size())
	{
		pair<long long,int> sm=q.top();
		q.pop();
		int wz=sm.second;
		if (vis[wz])
		{
			continue;
		}
		vis[wz]=1;
		for (int i=0;i<xd[wz].size();i++)
		{
			int v=xd[wz][i];
			if (dp[v]>dp[wz]+xt[wz][i])
			{
				dp[v]=dp[wz]+xt[wz][i];
				q.push({-dp[v],v});
			}
		 } 
	} 
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>xws;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		int zg;
		cin>>zg;
		for (int j=1;j<=zg;j++)
		{
			long long a,t;
			cin>>a>>t;
			vec[a+n].push_back(i);
			wec[a+n].push_back(t);
		}
	}
	memset(zj,0x3f,sizeof(zj));
	for (int i=n+1;i<=m+n;i++)
	{
		for (int j=0;j<vec[i].size();j++)
		{
			for (int k=j+1;k<vec[i].size();k++)
			{
				zj[vec[i][j]][vec[i][k]]=min(zj[vec[i][j]][vec[i][k]],wec[i][j]+wec[i][k]); 
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (zj[i][j]<=1000000000000)
			{
				xd[i].push_back(j);
				xt[i].push_back(zj[i][j]);
				xd[j].push_back(i);
				xt[j].push_back(zj[i][j]);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		dijkstra(i);
		for (int j=1;j<=n;j++)
		{
			sc[i][j]=dp[j];
		}
	}
	for (int i=1;i<=xws;i++)
	{
		int l,r;
		cin>>l>>r;
		long long kd=6000000000000000000;
		for (int i=0;i<vec[l+n].size();i++)
		{
			int yd=vec[l+n][i];
			for (int j=0;j<vec[r+n].size();j++)
			{
				int cd=vec[r+n][j];
				long long zh=wec[l+n][i];
				zh=zh+sc[yd][cd];
				zh=zh+wec[r+n][j];
				kd=min(kd,zh);
			}
		}
		cout<<kd+w[l]+w[r]<<"\n";
	}
}
