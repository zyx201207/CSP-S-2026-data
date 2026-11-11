#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,p,fe,fu,ans,x;
int w[1005];
int a[1002][1002],dis[1002][1002];
vector<int> y[1002];
bool l[1005];
int tu1[1001],zhi[1001];
queue<int> q;
void di(int qi)
{
	for (int i=1;i<=m;i++)
	{
		l[i]=0;
		dis[qi][i]=99999999;
		if (i==qi)
		{
			dis[i][i]=0;
			l[i]=1;
		}
	}
	q.push(qi);
	while (!q.empty())
	{
		//cout<<x<<" ";
		x=q.front();
		q.pop();
		for (int i=0,g;i<y[x].size();i++)
		{
			g=y[x][i];
			if (dis[qi][g]>dis[qi][x]+a[x][g])
			dis[qi][g]=dis[qi][x]+a[x][g];
			if (!l[g])
			{
				q.push(g);
				l[g]=1;
			}
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1,u,v1,e,v2,bz;i<=n;i++)
	{
		cin>>bz;
		for (int j=1;j<=bz;j++)
		{
			cin>>tu1[j]>>zhi[j];
			e=tu1[j];v2=zhi[j];
			for (int k=1;k<j;k++)
			{
				u=tu1[k];v1=zhi[k];
				if (a[u][e]!=0)
		        {
			       a[u][e]=min(a[u][e],v1+v2);
			       a[e][u]=min(a[e][u],v1+v2);
			       continue;
		        }
		        y[e].push_back(u);
		        y[u].push_back(e);
		        a[u][e]=v1+v2;
		        a[e][u]=v1+v2;
			}
		}
		//cout<<a[u][e]<<" ";
	}
	
	for (int i=1;i<=m;i++)
	di(i);
	//di(1);
	//for (int i=1;i<=m;i++)
	//{
		//cout<<y[i].size()<<" ";
		
	//	for (int j=0;j<y[i].size();j++)
	//	{
	//		cout<<i<<" "<<y[i][j]<<" "<<a[i][y[i][j]]<<"\n";
	//	}
	//}
	//for (int i=1;i<=m;i++)
	//{
	//	for (int j=1;j<=m;j++)
	//cout<<dis[i][j]<<" ";
	//cout<<"\n";
	//}
	for (int i=1,e,r;i<=p;i++)
	{
		cin>>e>>r;
		//cout<<dis[e][r]<<" ";
		cout<<w[e]+w[r]+dis[e][r]<<"\n";
	}
	return 0;
}
