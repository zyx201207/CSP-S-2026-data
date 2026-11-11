#include<bits/stdc++.h>
using namespace std;
#define int long long
int tim[505][20005];
int c,n,m,d,q;
const int N=5e5+10;
int dis[205][20005];
int dd[505];
int w[N];
vector<int> f[N];
struct edge{
	int to,li;
};
struct node{
	int id,dis,li;
};
vector<edge> e[N];
bool operator<(const node& a,const node& b){
	return a.dis>b.dis;
}
int vis[N];
int bfs(int sx,int sy){
	queue<node> que; 
	memset(dis,0x3f,sizeof(dis));
	for(int i=0;i<f[sx].size();i++){
		int v=f[sx][i];
		que.push({sx,tim[v][sx],v});
	} 
	while(que.size()){
		node u=que.front();
		que.pop();
		if(dis[u.id][u.li]<=u.dis)continue;
		dis[u.id][u.li]=u.dis;
		for(int i=0;i<e[u.id].size();i++){
			edge v=e[u.id][i];
			if(v.li!=u.li){
				que.push({v.to,u.dis+tim[u.li][u.id]+tim[v.li][u.id],v.li});
			}
			else que.push({v.to,u.dis,u.li});
		}
	}
	int minn=LONG_LONG_MAX;
	for(int i=1;i<=n;i++){
		minn=min(minn,tim[i][sy]+dis[sy][i]);
	} 
	return w[sx]+w[sy]+minn;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int last=-1;
		for(int j=1;j<=k;j++){
			int x=0,y=0;
			cin>>x;
			f[x].push_back(i);
			cin>>y;
			tim[i][x]=y;
			if(last!=-1){
				e[x].push_back({last,i});
				e[last].push_back({x,i});
			}
			last=x;
		}
	}
	while(q--){
		int sx,sy;
		cin>>sx>>sy;
		cout<<bfs(sx,sy)<<endl;
	}
	return 0;
}

