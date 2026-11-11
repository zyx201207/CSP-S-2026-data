#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+510;
const ll INF=1ll<<60;
int n,m;
ll w[M];
struct Edge{
	int to;
	ll t;
};
vector<Edge> g[M];
vector<ll> dist(M);
char f[M];
struct node{
	int inx;
	ll d;
	friend bool operator<(node n1,node n2){
		return n1.d>n2.d;
	}
};
priority_queue<node> pq;
char vis[M];
void dijkstra(int s){
	while(!pq.empty())pq.pop();
	pq.push({s,0});
	memset(vis,0,sizeof(vis));
	for(int i=0;i<m+n+5;i++)dist[i]=INF;
	dist[s]=0;
	vis[s]=1;
	while(!pq.empty()){
		int u=pq.top().inx;
		ll d=pq.top().d;
		pq.pop();
		for(auto e:g[u]){
			int v=e.to;
			ll t=e.t;
			if(!vis[v]&&dist[u]+t<dist[v]){
				dist[v]=dist[u]+t;
				pq.push({v,dist[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,q;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k,a;
		ll t;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d %lld",&a,&t);
			g[a].push_back({m+i,t});
			g[m+i].push_back({a,t});
		}
	}
	set<int> st;
	vector<pair<int,int>> qq,qq2;
	map<pair<int,int>,ll> ans;
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		st.insert(min(x,y));
		qq.push_back({min(x,y),max(x,y)});
	}
	qq2=qq;
	sort(qq2.begin(),qq2.end());
	int i=0;
	for(auto s:st){
		if(f[s]==0){
			f[s]=1;
			dijkstra(s);
			while(i<=q&&qq2[i].first==s){
				ans[{s,qq2[i].second}]=dist[qq2[i].second];
				i++;
			}
		}
	}
	for(auto p:qq){
		int x=p.first,y=p.second;
		printf("%lld\n",ans[p]+w[x]+w[y]);
	}
	return 0;
}