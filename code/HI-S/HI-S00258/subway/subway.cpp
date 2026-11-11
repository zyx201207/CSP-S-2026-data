#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PLI pair<ll,int>
#define PII pair<int,int>

const int N = 1e6+5;

const ll inf = 1e18;


int n,m,k[N],c,d,q,w[N];

int tot;

vector<int> a[N],t[N];

vector<PII> G[N];

vector<PII> T[N]; 

namespace Kruskal{
	int n,m = 0;
	
	struct UFS{
		int fa[N],siz[N];
		
		inline void init(void){
			for(int i = 1;i<=n;++i) siz[i] = 1,fa[i] = i;
		}
		
		inline int find(int u){
			if(u == fa[u]) return u;
			
			return fa[u] = find(fa[u]);
		}
		
		inline void merge(int x,int y){
			x = find(x),y = find(y);
			
			if(siz[x] > siz[y]) swap(x,y);
			
			siz[y] += siz[x],fa[x] = y;
		}
	}S;
	struct Edge{
		int u,v,w;
	}E[N];
	
	inline void Add(int u,int v,int w){
		E[++m] = {u,v,w};
	}
	
	inline bool cmp(Edge a,Edge b){
		return a.w < b.w;
	}
	
	inline void build(){
		n = tot;
		
		sort(E+1,E+m+1,cmp);
		
		S.init();
		
		int fail = 0;
		for(int i = 1;i<=m;++i){
			int u = E[i].u,v = E[i].v,w = E[i].w;
			
			if(S.find(u) != S.find(v)){
				S.merge(u,v);
				
				T[u].push_back({v,w});
				T[v].push_back({u,w});
				
				//cout << u << ' ' <<v << ' ' <<w<< '\n';
			}else ++fail;
			
			
		}
	}
}

inline void Link(int u,int v,int w){
	G[u].push_back({v,w});
	G[v].push_back({u,w});
	
	Kruskal::Add(u,v,w);
	//cout << u << ' ' << v <<' ' <<w << '\n'; 
}

vector<int> Bel[N];// i 被经过的 线路编号 

int Id[N][20];// 经过 i 的第 j 个线路的在图中的编号

inline int getId(int i,int j){//线路i 是第几个经过 点 j 
	for(int k = 0;k<Bel[j].size();++k)
		if(Bel[j][k] == i) return k;
} 

namespace Dijstra{
	ll dis[N<<1];
	
	bool vis[N<<1];
	
	priority_queue<PLI,vector<PLI>,greater<PLI> > q;
	
	inline ll Ask(int s,int t){
		for(int i = 1;i<=tot;++i) 
			dis[i] = inf,vis[i] = 0;
		
		dis[s] = 0;
		
		q.push({0,s});
		
		while(!q.empty()){
			
			int u = q.top().second;
			
			q.pop();
			
			if(vis[u]) continue;
			
			vis[u] = 1;
			
			for(int i = 0;i<G[u].size();++i){
				
				int v = G[u][i].first,w = G[u][i].second;
				if(dis[v] > dis[u] + w){
					dis[v] = dis[u] + w;
					
					q.push({dis[v],v}); 
				}
			}
		}
		
		return dis[t];
	}
}

namespace dis{
	ll Sw[N];
	
	int dfn[N],E[N<<1],tt,id,pos[N],fst[N];
	
	inline void dfs(int u,int fa){
		
		dfn[u] = ++id;
		
		E[++tt] = dfn[u];
		
		pos[dfn[u]] = u;
		
		fst[u] = tt;
		
		for(int i = 0;i<T[u].size();++i){
			int v = T[u][i].first,w = T[u][i].second;
			
			if(v == fa) continue;
			
			Sw[v] = Sw[u] + w;
			
			dfs(v,u);
			
			E[++tt] = dfn[u];
		}
	}
	
	int Mn[N<<1][21];
	inline void init(){
		dfs(1,0);
		
		for(int i = 1;i<=tt;++i) Mn[i][0] = E[i];
		
		for(int j = 1;j<=__lg(tt);++j)
			for(int i = 1;i<=tt-(1<<j)+1;++i)
				Mn[i][j] = min(Mn[i][j-1],Mn[i+(1<<j-1)][j-1]); 
	}
	
	inline int LCA(int u,int v){
		int l = fst[u],r = fst[v];
		
		if(l > r) swap(l,r);
		
		int x = __lg(r-l+1);
		
		return pos[min(Mn[l][x],Mn[r-(1<<x)+1][x])];
	}
	
	inline ll Ask(int u,int v){
		return Sw[u] + Sw[v] - (Sw[LCA(u,v)] << 1);
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1;i<=m;++i) cin >> w[i];
	
	for(int i = 1;i<=n;++i){
		cin >> k[i];
		
		a[i].resize(k[i]+1),t[i].resize(k[i]+1);
		
		for(int j = 1;j<=k[i];++j){
			cin >> a[i][j] >> t[i][j];
			
			Bel[a[i][j]].push_back(i);
		}
	}
	
	tot = m;
	
	for(int i = 1;i<=m;++i)//O(\sum k)
		for(int j = 0;j<Bel[i].size();++j)
			Id[i][j] = ++tot;
			
	for(int i = 1;i<=n;++i){// O(d \sum k) 
		for(int j = 1;j<=k[i];++j){
			int u = a[i][j];
			
			int x = Id[u][getId(i,u)];
			
			Link(x,u,t[i][j]);//台 -> 站 
			
			if(j<k[i]){
				int l = a[i][j+1];
				
				//cout << l << '\n';
				
				int y = Id[l][getId(i,l)];
				
				Link(x,y,0);// 台 -> 台 
			}
		}
	}
	
	Kruskal::build();
	dis::init();
	
	
	for(int i = 1,x,y;i<=q;++i){
		cin >> x >> y;
		
		//cout << dis::Ask(x,y) << ' ' << Dijstra::Ask(x,y) << '\n'; 
		
		ll ans;
		if(c<=8) ans = w[x] + w[y] + Dijstra::Ask(x,y);
		else ans = w[x] + w[y] + dis::Ask(x,y);
		
		cout << ans << '\n';
	}
	
	return 0;
}

