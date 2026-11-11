#include<bits/stdc++.h>
#define ll long long
#define pil pair<int,ll>
using namespace std;

const int INF=0x3f3f3f3f,P=998244353;
const ll LINF=0x3f3f3f3f3f3f3f3f;
const int N=505,M=5e5+5,T=1e6+1e3+5,lgT=20;
const int lM=1e4+5,lT=lM*2+510;
int c,n,m,d,q;
int t;
ll w[M];
vector<pil> ve[T];
vector<vector<ll> > dis;
vector<ll> tdis;

int fa[T][lgT];
bitset<T> vis;

inline void cnct(int u,int v,ll w){
	ve[u].push_back({v,w});
	ve[v].push_back({u,w});
}

struct Stt{
	int u;
	ll d;
	
	inline bool operator< (const Stt& oth) const{
		return d>oth.d;
	}
};
ll qry(int x,int y){
	if(dis[x][y]!=LINF) return dis[x][y];
	if(dis[y][x]!=LINF) return dis[y][x];
	for(int i=m+1;i<=t;++i) tdis[i]=LINF;
	for(int i=m+1;i<=t;++i) vis.reset(i);
	priority_queue<Stt> pq;
	tdis[m+x]=0;
	pq.push({m+x,0});
	while(not pq.empty()){
		int u;ll d;
		u=pq.top().u,d=pq.top().d;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=true;
		int v;ll ew;
		for(const pil& i:ve[u]){
			tie(v,ew)=i;
			if(vis[v] or tdis[v]<=d+ew) continue;
			tdis[v]=d+ew;
			pq.push({v,tdis[v]});
		}
	}
	for(int i=1;i<=m;++i){
		dis[x][i]=tdis[m+i];
	}
	dis[y][x]=dis[x][y];
	return dis[x][y];
}


void dfs(int u,int f,ll ds){
	fa[u][0]=f;
	dis[u][0]=ds;
	tdis[u]=tdis[f]+1;
	vis[u]=true;
	for(const auto& i:ve[u]){
		int v;
		ll w;
		tie(v,w)=i;
		if(vis[v]) continue;
		dfs(v,u,w);
	}
}
ll qry1(int x,int y){
	ll res=0;
	if(tdis[x]<tdis[y]) swap(x,y);
	for(int i=lgT-1;i>=0;--i){
		if(tdis[fa[x][i]]>=tdis[y]){
			res+=dis[x][i];
			x=fa[x][i];
		}
	}
	if(x==y) return res;
	for(int i=lgT-1;i>=0;--i){
		if(fa[x][i]!=fa[y][i]){
			res+=dis[x][i]+dis[y][i];
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	res+=dis[x][0];
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	t=m*2+n;
	for(int i=1;i<=m;++i){
		cin>>w[i];
		cnct(i,m+i,w[i]);
	}
	for(int i=1,k,a,t;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a>>t;
			cnct(m+a,(m<<1)+i,t);
		}
	}
	if(m<lM){
		tdis.resize(t+1);
		dis.resize(m+1);
		for(int i=1;i<=m;++i) vis.set(i);
		for(int i=1;i<=m;++i){
			dis[i].resize(m+1,LINF);
		}
		for(int i=1,x,y;i<=q;++i){
			cin>>x>>y;
			cout<<(qry(x,y)+w[x]+w[y])<<"\n";
		}
	}else{
		tdis.resize(t+1,0);
		dis.resize(t+1,vector<ll>(lgT,0));
		dfs(1,0,0);
		for(int j=1;j<lgT;++j){
			for(int i=1;i<=t;++i){
				fa[i][j]=fa[fa[i][j-1]][j-1];
				dis[i][j]=dis[i][j-1]+dis[fa[i][j-1]][j-1];
			}
		}
		for(int i=1,x,y;i<=q;++i){
			cin>>x>>y;
			cout<<qry1(x,y)<<"\n";
		}
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
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
