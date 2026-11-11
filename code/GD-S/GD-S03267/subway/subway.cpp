#include<bits/stdc++.h>
using namespace std;
#define int long long
// 地铁口 -w-> 地铁站v的站厅 
// n条地铁线路
// 经过k个地铁站  站台-t[i][j]->站厅 
// 每个地铁站d个线路
// q个计划
// 从x地铁口到y地铁口 n个站内换乘
// 还有测试点特化c
// q是1e5... 
// d<=20 似乎这是一个可以利用的性质
// 地铁口<->站厅的时间是一定的
// 问题就转换成怎么在不同的地铁站之间以最小的距离移动
// 似乎是全源最短路? 
// 只有500个点...
// 500*500*500 = 5e6+9
// 似乎也还可以 
// 20*500 = 1000条边
// 那就变成5e9了
// 还是有点难度的 
// 只要步行时间的话...我们是不是能直接算出来所有换乘点
// 500 * 20 = 10000
// hmmm 地铁站实际上是有5e5个
// 那难办了 
// 判断换乘站点数?
// 以地铁线路作为节点
// 对于每个线路,可以有联向其他线路的边,为换乘站的两个站点之和
// 所以大概的操作是:
// 1. 一个查询打过来,寻找对应的地铁站有哪些线路
// 2. 随便选一个线路,看看到另一个地铁站的线路要多久
// 不对,这样需要对每个线路都枚举,直接变成O(nm)了
// 那把地铁站也变成节点
// 地铁站 <-> 线路节点(双向边,带边权)
// 接着跑最短路
// ok 最短路写出来了 
// 到测试点16的样例开始就跑不动了
// 就这样吧,足够了. 
int c,n,m,d,q; 
const int N=1e6+9;
const int M=1e3+9;
int cnt;
struct SubwayStation{
	int out_time;
	int graph_id;
}station[N]; 

struct LineToStation{
	int to;
	int walk_time;
};
struct Line {
	vector<LineToStation>station;
	int graph_id;
}line[M];

struct GraphEdge{
	int to;
	int weight;
};
struct GraphNode{
	vector<GraphEdge>e;
	 
//	display(){
//		cout<<"Graph Node: ";
//		for(auto i : e){
//			cout<<i.to<<" ";
//		}
//		cout<<endl;
//	}
	
}g[N+M]; 

struct DijNode{
	int index;
	int weight;
	bool operator <(const DijNode &x)const {
		return index > x.index;
	}
}; 
priority_queue<DijNode> sq;

// 建图
void init(){
	for(int i=1;i<=n;i++){
		const int line_gid = line[i].graph_id;
		for(auto sta:line[i].station){
			const int to = sta.to;
			const int walk_time = sta.walk_time;
			g[line_gid].e.push_back({to,walk_time});
			g[to].e.push_back({line_gid,walk_time});
		}
	}
}
int dis[N+M];
bool visited[N+M];
int dij(int st,int ed){
	for(int i=1;i<=cnt;i++){
		dis[i] = INT_MAX;
		visited[i] = false;
	}	 
	while(!sq.empty()){
		sq.pop();
	} 
	
	dis[st] = 0; 
	sq.push({st,0});
	
	while(!sq.empty()){
		DijNode front = sq.top();
//		cout<<"front:"<<front.index<<endl;
//		g[front.index].display();
		sq.pop();
		if(visited[front.index]){
			continue;
		}	
		visited[st] = true;
		for(auto i : g[front.index].e){
			int new_dis = dis[front.index] + i.weight;
			if(dis[i.to] > new_dis){
				dis[i.to] = new_dis;
				sq.push({i.to,dis[i.to]});
			} 
		} 
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<dis[i]<<" ";
//	} 
//	cout<<endl;
	 
	return dis[ed];
} 

int query(int x,int y){
	int station_dis = dij(station[x].graph_id,station[y].graph_id);
	
	return station[x].out_time+station[y].out_time + station_dis; 
}  

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// 一定要记得取消注释!!!!! 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	// debug only freopen!!!!!
//	freopen("subway7.in","r",stdin);
//	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cnt++; 
		cin>>station[i].out_time;
		station[i].graph_id = cnt;
	}
	for(int i=1;i<=n;i++){
		cnt++;
		int k;
		cin>>k;
		line[i].graph_id = cnt;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			line[i].station.push_back({a,t});
		}
	}
	init(); 
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<query(x,y)<<'\n'; 
	} 
	
	return 0;
} 
