#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v,dis;
	bool operator <(node const &u)const {return dis > u.dis;}
};
bool vis[20505];
long long c,n,m,d,Q,dis[20505],w[20005];
priority_queue<node> q;
vector<pair<int,long long>> G[20505];
int q_dis(int x,int y){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[x] = 0;q.push({x,0});
	while(!q.empty()){
		auto tmp = q.top();q.pop();
		vis[tmp.v] = true;
		for(int i = 0;i < G[tmp.v].size();i++){
			if(G[tmp.v][i].first <= m && vis[G[tmp.v][i].first]) continue;
			if(dis[tmp.v] + G[tmp.v][i].second < dis[G[tmp.v][i].first]){
				dis[G[tmp.v][i].first] = dis[tmp.v] + G[tmp.v][i].second;
				q.push({G[tmp.v][i].first,dis[G[tmp.v][i].first]});
			}
		}
	}
	return dis[y] + w[x] + w[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		while(k--){
			int a , t;
			cin >> a >> t;
			G[a].push_back({m + i,t});
			G[m + i].push_back({a,t});
		}
	}
	while(Q--){
		int x,y;
		cin >> x >> y;
		cout<<q_dis(x,y)<<'\n';
	}
	return 0;
} 
