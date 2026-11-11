#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;
int c,n,m,d,p;
const int maxn = 5e5+5;
struct edge{
	int to,time;
};
vector<edge> g[maxn];
int st[maxn];
int vis[maxn];
int dis[maxn];
bool ifin(vector<edge>ss,int x,int y){
	bool a=false,b=false;
	for(int i=0;i<ss.size();i++){
		if(ss[i].to == x) a = true;
		if(ss[i].to == y) b = true;
	}
	return a&&b;
}
void dij(int start){
	memset(vis,false,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	vis[start] = true;
	dis[start] = 0;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push({0,start});
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		vis[u] = true;
		for(edge qq : g[u]){
			int to = qq.to;
			int w = qq.time;
			if(ifin(g[u],to,u)){
				if(dis[to] > dis[u]){
					dis[to] = dis[u];
					q.push({dis[to],to});
				}
			}else{
				if(dis[to] > dis[u]+w+st[to]){
					dis[to] = dis[u]+w+st[to];
					q.push({dis[to],to});
				}
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i=1;i<=m;i++){
		cin >> st[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		for(int i=1;i<=x;i++){
			int to,time;
			cin >> to >> time;
			g[i].push_back({to,time});	
		}
	}
	while(p--){
		int x,y;
		cin >> x >> y;
		int ans =st[x]+st[y];
		dij(x);
		ans += dis[y];
		cout << ans << endl;
	}
	return 0;
}


/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

