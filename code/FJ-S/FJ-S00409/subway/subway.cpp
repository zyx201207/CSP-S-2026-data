#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q;
struct lu{
	int v;
	int xianv;
};
struct lu2{
	int tim;
	int v;
	int xianv;
};
int w[500005],k[500005];
int a[505][10005],t[505][10005];
vector<lu>vec[5005];
long long ans=1e9;
vector<int>line[1005];
long long dijkstra(int s,int e,int li)
{
	long long d[100005];
	bool vis[100005]={false};
	for(int i=0;i<m;i++)
	{
		d[i]=1e9;
	}
	priority_queue<lu2,vector<lu2>,greater<lu2>>q;
	q.push({0,s,li});
	d[s]=0;
	vis[s]=true;
	while(!q.empty())
	{
		int u=(q.top()).v;
		int xian=(q.top()).xianv;
		q.pop();
		if(vis[u]) continue;
		for(int i=0;i<(int)vec[u].size();i++)
		{
			int v=vec[u][i].v;
			int xianv=vec[u][i].xianv;
			int tim=t[xian][u]+t[xianv][u];
			if(d[u]+tim<d[v])
			{
				d[v]=d[u]+tim;
				q.push({d[v],v,xianv});
			}
		}
	}
	return d[e];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			int u=a[i][j];
			line[u].push_back(k[i]);
			if(j>0)
			{
				int v=a[i][j-1];
				vec[u].push_back({v,k[i]});
				vec[v].push_back({u,k[i]});
			}
		}
	}
	while(Q--)
	{
		int s,e;
		cin>>s>>e;
		for(int i=0;i<(int)line[s].size();i++)
		{
			ans=min(ans,dijkstra(s,e,line[s][i]));
		}
		cout<<ans+w[s]+w[e]<<endl;
	}
	return 0;
}
