#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
int c,n,m,d,q;
int need[500010];
struct Road
{
	vector<pair<int,int>> v;//这条线路可以抵达的节点，以及出来的代价（必须走一次就出来，否则答案不优）	
}rode[510];
struct Node
{
	vector<pair<int,int>> road;//进入对应线路代价
}node[20010];
int val[20010];//初始代价 
int dist[20010][500];
struct State{
	int u,val,id;
	bool operator <(const State &a) const{
		return val < a.val;
	}
};
void bfs(int u,int v)
{
	priority_queue<State> q;
	for(int i =0;i<node[u].road.size();i++)
	{
		q.push({u,node[u].road[i].second,node[u].road[i].first});
		dist[u][node[u].road[i].first] = node[u].road[i].second;
	}
	while(!q.empty()){
		int step = q.top().val,u = q.top().u,id = q.top().id;
		q.pop();
		if(dist[u][id] < step) continue;
		for(int i = 0;i<rode[id].v.size();i++)
		{
			int wval = step + rode[id].v[i].second,v = rode[id].v[i].first;
			if(dist[v][id] > wval)
			{
				dist[v][id] = wval;
				q.push({v,wval,id});
			}
		}
		for(int i =0;i<node[u].road.size();i++)
		{
			q.push({u,step + node[u].road[i].second,node[u].road[i].first});
			dist[u][node[u].road[i].first] = step + node[u].road[i].second;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++) cin >> val[i];
	memset(dist,0x3f,sizeof dist);
	for(int i = 1;i<=n;i++)
	{
		int k;cin >> k;
		for(int j = 0;j<k;j++)
		{
			int v,cost;cin >> v >> cost;//进出路线代价 
			rode[i].v.push_back({v,cost});
			node[v].road.push_back({i,cost});
			dist[v][i] = 0;
		}
	}
	while(q--)
	{
		int u,v;
		cin >> u >> v;
		memset(dist,ox3,sizeof dist);
		bfs(u,v);
		int minans = INF;
		for(int i = 0;i<500;i++) minans = min(minans,dist[v][i]);
		cout << minans << '\n';
	}
	return 0;
}
//bool operator <(const A &a) const{
//	
//} 

//只有路线交集处，例如样例一中的 地铁站2，我们叫他换乘点
//此类点很关键 
//我们可以单独挑出来做一个预处理
//然后 对于起点和终点，分情况
//- 若在同一条路线上，很棒，只需要记录站厅和站台往返时间即可
//- 否则，在他们的路线上找到一个最短的方法 去到该节点 利用预处理数据进行O(1)回答查询
//

//如果两个节点都是关键点
//那不是最短路吗 
// 那么问题转化为：如何快速预处理关键点到终点对应路线的最短路问题

// 
 
 
//1000 0000 
