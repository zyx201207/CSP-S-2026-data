#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+10;
const ll M = 510;
const ll INF = LONG_LONG_MAX;
struct edge{
	ll ed,nxt,w;
}b[N*4];
ll nbs[N],tot;
void addedge(ll x,ll y,ll z){
	b[++tot].ed = y;
	b[tot].nxt = nbs[x];
	b[tot].w = z;
	nbs[x] = tot;
	return ;
}
ll c,n,m,D,Q;
ll w[N];
ll k[M];
ll dis[N];
ll vis[N];
vector < ll > a[M];
vector < ll > t[M];
vector < pair < ll,ll > > d[N];
struct node{
	ll u,dis;
	bool operator < (const node &x) const{
		return dis<x.dis;
	}
	bool operator > (const node &x) const{
		return dis>x.dis;
	}
};
priority_queue < node,vector < node >,greater < node > > q;
void dij(ll be){
	for(ll i=1;i<=m*n;i++){
		dis[i] = INF;
		vis[i] = 0;
	}
	dis[be] = 0;
	q.push({be,0});
	while(!q.empty()){
		node tmp = q.top();
		q.pop();
		ll u = tmp.u;
		if(vis[u]) continue;
		vis[u] = 1;
		for(ll i=nbs[u];i;i=b[i].nxt){
			ll v = b[i].ed;
			if(dis[v]>dis[u]+b[i].w){
				dis[v] = dis[u]+b[i].w;
				q.push({v,dis[v]});
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>D>>Q;
	//输入 
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	ll flag = 0;
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2) flag = 1;
		for(ll j=1,x,y;j<=k[i];j++){
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
		
	}
	//我们先来处理同一层的连边
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<k[i]-1;j++){
			addedge(a[i][j]+(i-1)*m,a[i][j+1]+(i-1)*m,0);
			addedge(a[i][j+1]+(i-1)*m,a[i][j]+(i-1)*m,0);
		}
	} 
	//然后我们来处理不同曾的边
	//我们先记录一个点在那些层中出现
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<k[i];j++){
			d[a[i][j]].push_back({i,t[i][j]});
		}
	}
	//然后我们建边
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<d[i].size();j++){
			for(ll s=j+1;s<d[i].size();s++){
				addedge(i+(d[i][j].first-1)*m,i+(d[i][s].first-1)*m,d[i][s].second+d[i][j].second);
				addedge(i+(d[i][s].first-1)*m,i+(d[i][j].first-1)*m,d[i][s].second+d[i][j].second);
			}
		}
	}
	//然后我们开始处理询问
	for(ll i=1,x,y;i<=Q;i++){
		cin>>x>>y;
		ll ret = INF;
		//我们依次尝试x的每一个七点
		for(ll j=0;j<d[x].size();j++){
			dij(x+(d[x][j].first-1)*m);
			//然后我们尝试y的每一个可能的到达的位置 
			for(ll s=0;s<d[y].size();s++){
				ret = min(ret,dis[y+(d[y][s].first-1)*m]+d[x][j].second+d[y][s].second+w[x]+w[y]);
			}
		} 
		cout<<ret<<endl;
	} 
	return 0;
}
/*
目前只能想到暴力
首先 我们这么想
如果说两条线路i,j存在公共元素x 
这就说明 我们可以通过
t[i][x]+t[j][x]的复杂度辗转在两条线路中
分层图
我们建立分层图 对于每一个点 他可以存在至多d条跨曾的便
一层表示一条线路
同层的线路的边权为0
那么这个就显然是最短路就好了
那么我们稍微计算一下
建图的复杂度是O(d^2 k)的
然后图的大小是n*m 的
然后跑最短路是O(n*mlog)的
 有一些分数


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

能过8个点 
*/
