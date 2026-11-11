#include <bits/stdc++.h>
using namespace std;


struct Road
{
	int v;
	int w;
};

int c,n,m,d,q;
int w[500001];
vector<vector<Road>> g(501001);

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	//把每一个地铁抽象成一个点，第i个地铁的编号为m+i 
	//对于站台i，地铁j，连一个 i<-(t[i][j]})->m+j 的无向边
	//答案最后加w[x]+w[y]
	if(c>=9 && c<=11)
	{
		priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;//Dijkstra 
		long long dist[501001];
		long long pre_ans[1001][1001];//全部预处理答案
		for(int i=1;i<=n;i++)
		{
			int k;
			cin >> k;
			for(int j=0;j<k;j++)
			{
				int a,t;
				cin >> a >> t;
				g[a].push_back({m+i,t});
				g[m+i].push_back({a,t});
			}
		}
		for(int i=1;i<=m;i++)//跑1~m节点再把答案全部存储起来 
		{
			int x=i;
			
			//初始化
			for(int j=1;j<=n+m;j++)
			{
				dist[j]=1e18;//距离 
			}
			
			dist[x]=0;
			pq.push({0,x});
			while(!pq.empty())
			{
				int d=pq.top().first;
				int u=pq.top().second;
				pq.pop();
				
				//cout << "[info]检查状态" << u << " " << dist[u] << endl;
				
				if(d!=dist[u])continue;//保证实时是最新状态
				
				//cout << "[info]开始松弛" << u << " " << d << endl;
				//cout << "[info]松弛节点数" << g[u].size() <<endl;
				for(int i=0;i<g[u].size();i++)
				{
					int v=g[u][i].v;
					int w=g[u][i].w;
					//cout << "[info]松弛" << v << endl;
					if(dist[v]>dist[u]+w)
					{
						dist[v]=dist[u]+w;
						pq.push({dist[v],v});
						//cout << " - [high]松弛成功" << v << " " << dist[v] << endl;
					}
				} 
			}
			for(int j=1;j<=m;j++)pre_ans[i][j]=dist[j]+w[i]+w[j];
			//cout << "---------------------------------" << '\n';
		}
		for(int i=0;i<q;i++)
		{
			int x,y;
			cin >> x >> y;
			cout << pre_ans[x][y] << '\n';
		}
	}
	else if(c>=12 && c<=19)
	{
		int T;
		for(int i=1;i<=n;i++)
		{
			int k;
			cin >> k;
			for(int j=0;j<k;j++)
			{
				int a,t;
				cin >> a >> t;
				T=t;
				g[a].push_back({m+i,t});
				g[m+i].push_back({a,t});
			}
		}
		//跑BFS 
		for(int i=0;i<q;i++)
		{
			int x,y;
			cin >> x >> y;
			
			//初始化
			bool vis[m+n+1]={};//是否遇到过 
			queue<pair<long long,int>> bfs;
			
			bfs.push({0,x});
			while(!bfs.empty())
			{
				int d=bfs.front().first;
				int u=bfs.front().second;
				bfs.pop();
				
				//cout << "[info]检查状态" << u << " " << dist[u] << endl;
				
				if(vis[u])continue;//保证实时是最新状态
				vis[u]=true;
				if(u==y)//找到目标 
				{
					cout << d+w[x]+w[y] << '\n';
					break; 
				}
				
				//cout << "[info]开始松弛" << u << " " << d << endl;
				//cout << "[info]松弛节点数" << g[u].size() <<endl;
				for(int i=0;i<g[u].size();i++)
				{
					int v=g[u][i].v;
					//cout << "[info]松弛" << v << endl;
					if(!vis[v])
					{
						bfs.push({d+T,v});
					}
				} 
			}
			//cout << "---------------------------------" << '\n';
		}
	}
	else
	{
		priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;//Dijkstra 
		long long dist[501001];
		for(int i=1;i<=n;i++)
		{
			int k;
			cin >> k;
			for(int j=0;j<k;j++)
			{
				int a,t;
				cin >> a >> t;
				g[a].push_back({m+i,t});
				g[m+i].push_back({a,t});
			}
		}
		for(int i=0;i<q;i++)
		{
			int x,y;
			cin >> x >> y;
			
			//初始化
			for(int j=1;j<=n+m;j++)
			{
				dist[j]=1e18;//距离 
			}
			
			dist[x]=0;
			pq.push({0,x});
			while(!pq.empty())
			{
				int d=pq.top().first;
				int u=pq.top().second;
				pq.pop();
				
				//cout << "[info]检查状态" << u << " " << dist[u] << endl;
				
				if(d!=dist[u])continue;//保证实时是最新状态
				
				//cout << "[info]开始松弛" << u << " " << d << endl;
				//cout << "[info]松弛节点数" << g[u].size() <<endl;
				for(int i=0;i<g[u].size();i++)
				{
					int v=g[u][i].v;
					int w=g[u][i].w;
					//cout << "[info]松弛" << v << endl;
					if(dist[v]>dist[u]+w)
					{
						dist[v]=dist[u]+w;
						pq.push({dist[v],v});
						//cout << " - [high]松弛成功" << v << " " << dist[v] << endl;
					}
				} 
			}
			cout << dist[y]+w[x]+w[y] << '\n';
			//cout << "---------------------------------" << '\n';
		}
	}	
}
