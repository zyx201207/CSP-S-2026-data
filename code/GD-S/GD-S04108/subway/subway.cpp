#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long c,n,m,d,q,w[N],walk[500][N],k,x,y,root,vis[N],vis1[N],dis[N],output,lst;
struct node
{
	long long v,w,lne;
};
vector<node> e[N];

inline long long dfscheck(long long s,long long fa,long long enddot,long long nowlne)
{
	if(s==enddot)
	{
		return walk[nowlne][enddot];
	}
	for(auto ed:e[s])
	{
		if(!vis[ed.v]&&ed.lne==nowlne)
		{
			dfscheck(ed.v,s,enddot,nowlne);
		}
	}
	return 0x3f3f3f3f3f3f3f3f;
}

inline long long dijkstra(long long s,long long nowlne,long long enddot)//假设起点和终点都不在同一条线上 
{
	for(int i=1;i<=m;i++)
	{
		dis[i]=0x3f3f3f3f3f3f3f3f;
	}
	priority_queue<pair<long long,pair<long long,long long>>> pq;
	pq.push({0,{s,nowlne}});
	dis[s]=0;
	//cout<<"现在的dis[3]为"<<dis[3]<<"\n";
	while(pq.size())
	{
		auto x=pq.top();
		pq.pop();
		int u=x.second.first,lne=x.second.second;
		if(vis1[u]>q)
		{
			continue;
		}
		vis[u]++;
		//cout<<"现在对点"<<u<<"松弛，dis["<<u<<"]="<<dis[u]<<"\n";
		for(auto x:e[u])
		{
			//cout<<"现在的dis[3]为"<<dis[3]<<"\n";
			int v=x.v,w=x.w,lne_=x.lne;
			//cout<<"访问点"<<v<<"，其所在线路为"<<lne_<<"\n";
			if(dis[v]>dis[u]+w&&lne==lne_)//同一条线上的两个站，距离就是原本的dijkstra求法 
			{
				dis[v]=dis[u]+w;
				if(v==enddot)
				{
					dis[v]+=walk[lne][v];
				}
				//cout<<"计算。\n";
				pq.push({-dis[v],{v,lne}});
			}
			else  if(dis[v]>dis[u]+w+walk[nowlne][u]+walk[lne][u]&&lne!=lne_)//不同线路上的两个站，距离需要加上换成距离 
			{
				dis[v]=dis[u]+w+walk[lne][u]+walk[lne_][u];
				if(v==enddot)
				{
					dis[v]+=walk[lne_][v];
				}
				//cout<<"计算换乘：从线路"<<lne<<"换为"<<lne_<<"\n";
				pq.push({-dis[v],{v,lne_}});
			}
			//cout<<"现在对点"<<v<<"松弛完毕，其dis为"<<dis[v]<<"\n";
		}
	}
	return dis[enddot];
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		lst=0;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>y;
			if(i==1&&j==1)
			{
				root=x;
			}
			if(lst)
			{
				e[lst].push_back({x,0,i});
				e[x].push_back({lst,0,i});
			}
			walk[i][x]=y;
			vis[x]++;
			lst=x;
		}
	}
	//dfs(root,1,0);
	while(q--)
	{
		output=0x3f3f3f3f3f3f3f3f;
		cin>>x>>y;
		for(auto ls:e[x])
		{
			int nowlne_=ls.lne;
			output=min(output,walk[nowlne_][x]+dijkstra(x,nowlne_,y));
			output=min(output,walk[nowlne_][x]+dfscheck(x,-1,y,nowlne_));
		}
		cout<<output+w[x]+w[y]<<endl;
	}
}
