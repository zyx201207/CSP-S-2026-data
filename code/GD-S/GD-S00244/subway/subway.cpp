#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N=505,M=6e5+5,inf=1e18;
bool vis[N];
vector<pii> zh[M];
vector<pii> oo[N];
int c,n,m,d,q,t[M],dd[N][N],dis[N];
priority_queue<pii,vector<pii>,greater<pii>> pq;
struct Edge{
	int v,w,nxt;
} e[N*N*3];
int hd[M],cnt;
void add(int u,int v,int w){
	e[++cnt]={v,w,hd[u]};
	hd[u]=cnt;
}
void dij(int x){
	for(int i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
	dis[x]=0;
	pq.emplace(0,x);	
	while(!pq.empty()){
		int u=pq.top().second;
		int d=pq.top().first;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				pq.emplace(dis[v],v);
			}
		}
	}
	for(int i=1;i<=n;i++) dd[x][i]=dis[i];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>t[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		oo[i].reserve(k);
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			zh[v].emplace_back(i,w);
			oo[i].emplace_back(v,w);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[j]=inf;
		dis[i]=0;
		for(pii o1:oo[i]){
			int v=o1.first,w1=o1.second;
			for(pii o2:zh[v]) {
				int k=o2.first,w2=o2.second;
				dis[k]=min(dis[k],w1+w2);
			}
		}
		for(int j=1;j<=n;j++){
			add(i,j,dis[j]);
			add(j,i,dis[j]);
		}
	}
	for(int i=1;i<=n;i++) dij(i);
	while(q--){
		int a,b;
		cin>>a>>b;
		int ans=inf;
		for(pii o1:zh[a])
			for(pii o2:zh[b]){
				ans=min(ans,o1.second+o2.second+dd[o1.first][o2.first]);
			}
		ans+=t[a]+t[b];
		cout<<ans<<'\n';
	}
	return 0;
}
