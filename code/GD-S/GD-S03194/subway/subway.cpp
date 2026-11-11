#include<bits/stdc++.h>
using namespace std;
const int N=6e5+9,M=501;
const long long INF=LONG_LONG_MAX;
int c,n,m,d,q,t;
long long dis[N];
int cnt=0,W[N];
map<int ,long long> minn[M];
int vis[N];
struct node{
	int id,w;
};
vector<node> f[N];
struct P{
	int u;
	long long w;
	bool operator<(const P&other)const{
		return other.w<w;
	}	
};
priority_queue<P> Q;
void dij(int s){
	for(int i=1;i<=cnt;i++)dis[i]=INF;
	dis[s]=0;
	Q.push({s,0});
	while(!Q.empty()){
		int u=Q.top().u;
		long long D=Q.top().w;
		Q.pop();
		if(dis[u]!=D)continue;
		for(node to:f[u]){
			int v=to.id;
			long long w=to.w;
			if(dis[v]>D+w){
				dis[v]=D+w;
				Q.push({v,dis[v]});
			}
		}
	}
	return ;
}
struct nd{
	int u,v;
};
vector<nd> g;
int tag[N];
void bfs(int s){
	for(int i=1;i<=cnt;i++)dis[i]=INF;
	memset(tag,0,sizeof(tag));
	vector<int > now,later;
	int res=0;
	now.push_back(s);
	tag[s]=1;
	dis[s]=0;
	while(!now.empty()){
		res++;
		swap(now,later);
		now.clear();
		for(int x:later){
			for(node to:f[x]){
				int v=to.id;
				if(!tag[v]){
					tag[v]=1;
					dis[v]=res*t;
					now.push_back(v);
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	cnt=m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		cnt++;
		for(int j=1;j<=k;j++){
			int u,w;
			cin>>u>>w;
			t=w;
			f[u].push_back({cnt,w});
			f[cnt].push_back({u,w});
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		for(node x:f[u])vis[x.id]=1;
		g.push_back({u,v});
		vis[v]=1;
	}
	for(int i=1;i<=n;i++){
		int p=i+m;
		if(!vis[p])continue;
		if(c>=16&&c<=19)bfs(p);
		else dij(p);
		for(int j=1;j<=m;j++){
			if(vis[j])minn[i][j]=dis[j];
		}
	}
	for(nd x:g){
		int u=x.u,v=x.v;
		long long MIN=INF;
		for(node A:f[u]){
			MIN=min(MIN,minn[A.id-m][v]+A.w);
		}
		cout<<MIN+W[u]+W[v]<<'\n';
	}
	return 0;
} 
//D:\data\subway\subway4.ans
//D:\GD-S03194\subway\subway.out
