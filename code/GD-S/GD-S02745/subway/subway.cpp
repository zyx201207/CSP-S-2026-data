#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，出行计划数，每条线站数 
long long w[10005];//地铁口到站厅的时间 
long long a[505][10005];//线路的站点 从站台到站厅的时间 
int a1;
long long t;//输入相关 
int l,r;//起点，终点
long long ans=-1;
vector<int> z[10005];
long long f[10005];//dfs 
void dfs(int st, int xl, long long tm)//当前站点，当前线路，到当前站点所需的时间
{
	for( int u : z[st] )//遍历每一条线 
	{
		if(st!=l && u==xl) continue;
		long long gxsj=tm+a[xl][st]+a[u][st];//更新时间（起点到换乘站+出换乘站厅+入换乘站台） 
		if(st==l) gxsj=a[u][st];//若该站点是起点，更新时间（入起点站台）
		for(int i=1;i<=m;i++)//遍历每一个站点 
		{
			if(a[u][i]==0) continue;//若该线没有经过该站点，则跳过 
			if(i==r)//若该站点是终点 
			{
				if(ans==-1 || ans<gxsj+a[u][i]+w[l]+w[r])//如果答案为空或比答案更小 
				{
					ans=gxsj+a[u][i]+w[l]+w[r];//更新答案（更新时间+出终点站厅+出入起终点地铁口） 
				}
				break;//答案已更新，没必要再遍历这条线的了 
			}
			if(f[i]==-1 || f[i]<gxsj)
			{
				f[i]=gxsj;//更新该站点的时间，即从起点到换乘站点加出到换乘站厅加进入换成站台 
				dfs(i,u,f[i]);//更新这个站点
			} 
		}
	}
	return;
} 
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a1>>t;
			a[i][a1]=t;
			z[a1].push_back(i);
		}
	}
	for(int rou=1;rou<=q;rou++)
	{
		cin>>l>>r;
		int qd;
		for(int u:z[l])
		{
			qd=u;
		}
		ans=-1;
		memset(f,-1,sizeof(f));
		f[l]=0;
		dfs(l,qd,0);
		cout<<ans<<endl;
	}
	return 0;
} 
