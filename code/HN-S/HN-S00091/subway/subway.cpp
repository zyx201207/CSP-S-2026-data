#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+100;
int a[maxn],s[maxn];
struct node{
	int x,w;
	const operator < (const node &a)const {
		return a.w<w;
	}
};
priority_queue<node>q;
vector<node>g[maxn];
int dis[maxn],w[maxn];
bool vis[maxn];
int m;
void dijkstra(int x){
	q.push({x,0});
	dis[x] = 0;
	while(!q.empty()){
		int cur = q.top().x;
		q.pop();
		if(vis[cur])continue;
		vis[cur] = 1;
		int siz = g[cur].size();
		for(int i = 0;i<siz;i++){
			int nxt = g[cur][i].x,w = g[cur][i].w;
			if(dis[nxt]>dis[cur]+w){
				dis[nxt] = dis[cur]+w;
				if(!vis[nxt])q.push({nxt,w});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,d,q,k,x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)cin>>w[i];
	for(int i = 1;i<=n;i++){
		cin>>k;
		int ty;
		for(int j = 1;j<=k;j++){
			cin>>x>>y;
			g[x].push_back({m+i,y});
			g[m+i].push_back({x,y});
		}
	}
	while(q--){
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
} 
