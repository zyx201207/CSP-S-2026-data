#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+505;
const int INF=0x3f3f3f3f;
int c,n,m,d,qq,k,ans=0;
int w[N];
struct node{
	int to;
	int val;
};
struct edg{
	int c;
	int id;
	bool operator >(const edg &a) const {
		return c>a.c;
	}
};
bool vis[N];
int dist[N];
vector<node> e[N];
priority_queue<edg,vector<edg>,greater<edg> > q;
void dij(int st){
	for(int i=1;i<=m+n;i++){
		dist[i]=INF;
		vis[i]=0;
	} 
	dist[st]=0;
	q.push({0,st});
	while(!q.empty()){
		edg t=q.top();
		q.pop();
		if(vis[t.id]) continue;
		vis[t.id]=1;
		int u=t.id;
		for(auto i:e[u]){
			if(dist[i.to]>dist[u]+i.val){
				dist[i.to]=dist[u]+i.val;
				q.push({dist[i.to],i.to});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++) cin>>w[i];
	int x,t;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>t;
			e[x].push_back({i+m,t});
			e[i+m].push_back({x,t});
		}
	}
	while(qq--){
		int u,v;
		cin>>u>>v;
		ans=w[u]+w[v];
		dij(u);
		ans+=dist[v];
		cout<<ans<<'\n';
	}
	return 0;
} 
