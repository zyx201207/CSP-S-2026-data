#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int M=5e5+5;
const int INF=1e18+5; 
int n,m,d,p,w[N],dist[N][N];
bitset<N+M> vis;
bitset<N> vis_ans;
struct node{
	int id,dis;
	friend bool operator<(node x,node y){
		return x.dis>y.dis;
	}
};
vector<node> g[N+M];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void dijkstra(int s){
	priority_queue<node> q;
	q.push({s,0ll});
	vis.reset();
	for(int i=1;i<=n;i++) dist[s][i]=INF;
	while(q.size()){
		node opt=q.top();
		q.pop();
		int id=opt.id,dis=opt.dis;
		if(vis[id]) continue;
		vis[id]=1;
		for(auto v:g[id]){
			int u=v.id,w=v.dis;
			if(dist[s][u]>dist[s][id]+w){
				dist[s][u]=dist[s][id]+w;
				q.push({u,dist[s][u]}); 
			}
		}
	}
	return ;
}
void solve(){
	n=read(),m=read(),d=read(),p=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int L=read();
		for(int j=1;j<=L;j++){
			int x=read(),y=read();
			g[x].push_back({i+n,y});
			g[i+n].push_back({x,y});
		}
	}
	while(p--){
		int sx=read(),sy=read();
		dijkstra(sx);
		vis_ans[sx]=1;
		cout<<w[sx]+w[sy]+dist[sx][sy]<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read();
	solve();
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
