//CSP2026 t2 60pts
#include<bits/stdc++.h>
#define int long long
#define rint register int
#define endl '\n'
#define gc getchar
#define pc putchar
using namespace std;
const int N=5e5+505,inf=0x3f3f3f3f3f3f3f3f;
struct node{
	int u,dis;
	bool operator <(const node& b)const{
		return dis>b.dis;
	} 
};
struct edge{int v,w;};
vector<edge> G[N];
int c,n,m,d,Q;
int w[N];
int dis[N];
bitset<N> vis;
inline int rd(){
	rint res=0,p=1;
	register char ch=gc();
	
	for(;ch<'0'||ch>'9';ch=gc()) if(ch=='-') p=-p;
	for(;ch>='0'&&ch<='9';ch=gc()) res=(res<<3)+(res<<1)+(ch^48);
	return res*p; 
}
inline void wt(const rint& x){
	if(x>9) wt(x/10);
	pc(x%10+48);
}
inline void init(){
	for(rint i=1;i<=n+m;++i)
		dis[i]=inf,vis[i]=0;
}
inline void dijkstra(const rint& s,const rint& t){
	init();
	priority_queue<node> pq;
	pq.push({s,0});
	dis[s]=0;
	while(!pq.empty()){
		auto tmp=pq.top();pq.pop();
		rint u=tmp.u,udis=tmp.dis;
		if(vis[u]) continue;
		vis[u]=1;
		if(u==t) return;
		for(auto e:G[u]){
			rint v=e.v,w=e.w;
			if(dis[v]>udis+w){
				dis[v]=udis+w;
				pq.push({v,dis[v]});
			}
		}
	}
}

signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	while(cin>>c>>n>>m>>d>>Q){
		for(rint i=1;i<=m;++i)
			w[i]=rd();
		
		for(rint i=1;i<=n;++i){
			rint k,v,w;
			k=rd();
			for(rint j=1;j<=k;++j){
				v=rd();w=rd();
				G[i+m].push_back({v,w});
				G[v].push_back({i+m,w});
			}
		}
		
		while(Q--){
			rint x,y;
			x=rd();y=rd();
			dijkstra(x,y);
			wt(dis[y]+w[x]+w[y]);
			pc('\n');
		}
		for(rint i=1;i<=n+m;++i)
			G[i].clear();
	}
	return 0;
}

