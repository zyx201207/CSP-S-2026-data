#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ifstream fin("subway.in");
ofstream fout("subway.out");

#define cin fin
#define cout fout

const ll N=510,M=5e5+10,D=20,Q=1e5+10;

/*
思路：首先，这看起来像一道图论，也是最短路径类问题
无负权，我们可以使用迪杰斯特拉

首先，一个站本身出入站需要花费一些时间
然后，一次换乘操作也需要花费时间，这个时间是多少呢？
其实就是原线路在换乘站处的进站花费和新线路在换乘站的出站花费之和
如果不在一个站换乘，代价就是0
同时，需要考虑初始时入站花费的时间 ，和结束时出站花费的时间
我们可以把他抽象成一次滚木到第一线路的换乘，和最后一线路到滚木的换乘
只有起点和终点有，其他点没有 
我们需要用迪杰斯特拉跑出最优换乘规划*/


// c测试点编号
// n地铁线路数
// m地铁站数
// d每个地铁站最多被多少条线路经过
// q出行计划数 
ll c,n,m,d,q;
ll w[M]; // 每个地铁站进出站的固定耗时
struct Edge{
	ll line,to,w;
	bool operator>(const Edge& other) const {
		return this->w > other.w;
	}
};
vector<Edge> e[M];
#define HEAD M-2
#define TAIL M-1
ll dist[M];
const ll inf = 99999999999;
struct Way{
	ll line,to,w,pre;
	bool operator>(const Way& other) const {
		return this->w > other.w;
	}
};

void solve(ll sta, ll end) {
	for (ll i=0; i<=m; ++i) {
		dist[i] = inf;
	}
	dist[HEAD] = 0;
	dist[TAIL] = inf;
	e[end].push_back({-1,TAIL,w[end]}); // -1线（不存在），代表最后一次滚木换乘 
	priority_queue<Way,vector<Way>,greater<Way> > pq;
	pq.push({0,HEAD,0,w[sta]}); // 0线（不存在） 
	// 典中典之dijkstra
	while (!pq.empty()) {
		Way top = pq.top();
		pq.pop();
		if (top.w > dist[top.to]) continue;
		for (Edge nxt: e[top.to]) {
			// 本线（不换乘，无代价） 
			if (nxt.line==top.line) {
				pq.push({top.line,nxt.to,top.w,nxt.w});
				continue;
			}
			// 执行换乘
			ll tim = top.w+top.pre+nxt.w;
			if (tim < dist[nxt.to]) {
				dist[nxt.to] = tim;
				pq.push({nxt.line,nxt.to,tim,nxt.w});
			}
		}
	}
	e[end].pop_back();
	cout<<dist[TAIL]<<'\n';
}

int main() {
	cin>>c>>n>>m>>d>>q; 
	for (ll i=1; i<=m; ++i) {
		cin>>w[i];
	}
	for (ll i=1; i<=n; ++i) {
		ll k; cin>>k;
		ll pre = HEAD;
		for (ll l=1; l<=k; ++l) {
			ll a,t; cin>>a>>t;
			e[pre].push_back({l,a,t});
			pre = a;
		}
		// e[pre].push_back({TAIL,w[pre]});
	}
	for (ll i=1; i<=q; ++i) {
		ll x,y; cin>>x>>y;
		solve(x,y);
	}
	return 0;
}
