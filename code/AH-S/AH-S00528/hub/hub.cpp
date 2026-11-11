#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=20;
typedef struct Edge{
	int to,next,w;
}Edge;
Edge e[N<<1];
int ct,head[N];
int id,t;
int n,k;
int fa[N];
bool inP[N];
int dist[N][N];
int ans=LLONG_MAX;
inline void addEdge(int u,int v,int w){
	e[++ct].to=v;
	e[ct].w=w;
	e[ct].next=head[u];
	head[u]=ct;
}
inline int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
inline void unionn(int x,int y){
	fa[x]=y;
}
inline void dfs(int u,int fa){
	if(inP[u]&&inP[fa]){
		int fx=find(u);
		int fy=find(fa);
		if(fx!=fy)unionn(fx,fy);
	}
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==fa)continue;
		dfs(v,u);
	}
}
inline void init(int mask){
	int tot=0;
	for(int i=1;i<=n;++i){
		fa[i]=i;
		inP[i]=false;
	}
	vector<int> Points;
	for(int i=1;i<=n;++i){
		if(((mask>>(i))&1)==1){
			++tot;
			Points.push_back(i);
			inP[i]=true;
		}
		if(tot>k)return ;
	}
	if(tot!=k){
		return ;
	}
	dfs(1,0);
	unordered_map<int,int> mp;
	int kind=0;
	for(auto p:Points){
		if(mp[fa[p]]==0)++kind;
		mp[fa[p]]++;
	}
	if(kind>2)return ;
	int mx=-2;
	for(int i=1;i<=n;++i){
		int mn=LLONG_MAX;
		for(auto p:Points){
			mn=min(dist[i][p],mn);
		}
		mx=max(mx,mn);
	}
	ans=min(mx,ans);
}
inline void solve(){
	memset(dist,0x3f3f3f3f,sizeof(dist));
	ct=0;
	ans=LLONG_MAX;
	memset(head,0,sizeof(head));
	cin>>n>>k;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		addEdge(u,v,1);
		addEdge(v,u,1);
		dist[u][v]=1;
		dist[v][u]=1;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			dist[i][i]=0;
			for(int j=1;j<=n;++j){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	for(int i=0;i<=(1<<n);++i){
		init(i);
	}
	if(ans!=LLONG_MAX)cout<<ans<<'\n';
	else cout<<"0\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>id>>t;
	while(t--)solve();
	return 0;
}
