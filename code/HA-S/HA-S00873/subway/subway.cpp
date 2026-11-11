//第二道题 
//只写特殊性质 B 
#include<bits/stdc++.h>
using namespace std;
int c;
int n,m,d,q;
//线路数、站数、最多线路、计划数 
vector<int> w;//口->站的时间 
vector<vector<int>> station;//所属地铁线路 
vector<vector<int>> dist;
struct Edge{
	int id,dis,next;
};
int head[500005];
Edge a[1000005];
int num=0;
void add(int u,int v,int w)
{
	a[++num]={v,w,head[u]};
	head[u]=num;
}
//vector<vector<pair<int,int>>> a;
void dijkstra(int s)
{
	vector<bool> vis(m+5,false);
	queue<pair<int,int>> q;
	q.push({0,s});//从属线路 节点 
	dist[s][s]=0;
	while(!q.empty())
	{
		int u=q.front().second;
		int line=q.front().first;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=true;
		//for(int i=0;i<a[u].size();i++)
		for(int i=head[u];i!=-1;i=a[i].next)
		{
			//int v=a[u][i].first;//终点 
			//int w=a[u][i].second;//线路 
			int v=a[i].id;//终点 
			int w=a[i].dis;//线路 
			if(vis[v])
			{
				continue;
			}
			if(line==0||line==w)//无从属线路 或 在同一线路上 
			{
				if(dist[s][v]>=dist[s][u])
				{
					dist[s][v]=dist[s][u];
					q.push({w,v});
				}
			}else{//不在同一条线路上 
				if(dist[s][v]>=dist[s][u]+1)
				{
					dist[s][v]=dist[s][u]+1;
					q.push({w,v});
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(head,-1,sizeof(head));
	//a.resize(m+5);
	w.resize(m+5,0);
	dist.resize(m+5,vector<int>(m+5,0x3f3f3f3f));
	station.resize(m+5,vector<int>(0));
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	int t=0;//站厅到站台的时间 
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		int last=-1;
		for(int j=1;j<=k;j++)
		{
			int s;//经过的地铁站 
			scanf("%d",&s);
			scanf("%d",&t);//站厅->站台的时间 
			station[s].push_back(i);
			if(last!=-1)
			{
				//a[s].push_back({last,i});
				//a[last].push_back({s,i});
				add(s,last,i);
				add(last,s,i);
			}
			last=s;
		}
	}
	/*for(int i=1;i<=m;i++)
	{
		printf("起点为%d\n",i);
		for(int j=1;j<=m;j++)
		{
			printf("    终点为:%d\n",j);
			printf("    换乘次数为:%d\n\n",dist[i][j]);
		}
	}*/
	while(q--)
	{
		int begin,end;
		scanf("%d%d",&begin,&end);
		if(dist[begin][begin]==0x3f3f3f3f)
		{
			dijkstra(begin);
		}
		printf("%d\n",w[begin]+t+w[end]+t+dist[begin][end]*t*2);
	}
	
	return 0;
}
