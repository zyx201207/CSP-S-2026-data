#include <bits/stdc++.h> 
using namespace std; 
const int N = 505,M = 5e5 + 5,D = 25,Q = 1e5 + 5;
const long long INF = 1e15;
int c,n,m,d,q,x[Q],y[Q];
int w[M],k[D];
vector<pair<int,int>> e[M + N];//pair表示[目标点，走路时间 ],前m个数据表示站点，后n个数据表示线路编号 
void add(int a,int b,int val){
	e[a].push_back({b,val});
	e[b].push_back({a,val});
	return;	
}
long long dis[M + N];
bool vis[M + N];
struct node{
	int st;
	long long dis;
	
	bool operator < (const node b) const{
		return b.dis < dis;
	}
};
priority_queue<node,vector<node> > pq;
long long dijkstra(int start,int end){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	pq.push({start,0});
	while(!pq.empty()){
		node nx = pq.top();
		pq.pop();
		if(vis[nx.st]) continue;
		vis[nx.st] = true;
		dis[nx.st] = min(nx.dis,dis[nx.st]);
		if(nx.st == end){
			//cout << nx.st << ' ' << dis[nx.st] << endl;
			//cout << 1 << endl;
			//return dis[end];	
			
		} 
		//cout << dis[end] << ' ';
		
		for(int i = 0;i < e[nx.st].size();i++){
			if(vis[e[nx.st][i].first]) continue;
			//cout << e[nx.st][i].first << ' ' << dis[nx.st] + e[nx.st][i].second << endl;
			if(dis[nx.st] + e[nx.st][i].second < dis[e[nx.st][i].first]){
				node ny;
				ny.st = e[nx.st][i].first;
//				if(ny.st == end){
//					cout << 2 << endl;
//				}
				ny.dis = (long long)(dis[nx.st] + e[nx.st][i].second);
				pq.push(ny);
			}
		}
		
	}
	//cout << 3 << endl;
	return dis[end];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		int a2 = 0,t;
		for(int j = 1;j <= k[i];j++){	
			cin >> a2 >> t;
			add(a2,i + m,t);
			
			
		}
	}
	for(int i = 1;i <= q;i++){
		cin >> x[i] >> y[i];
//		cout << x << y << endl;
		cout << w[x[i]] + w[y[i]] + dijkstra(x[i],y[i]) << endl;
	}
	return 0;
}
