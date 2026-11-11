#include<bits/stdc++.h>
using namespace std;
constexpr int N=500+5;
constexpr int M=5e5+5; 
constexpr int V=5.1e5+5;
constexpr int E=1e7+5;
int c,n,m,d,q,w[M],k,a,t,x,y;
int head[V],tot,to[E<<1],nxt[E<<1],val[E<<1];
void add(int u,int v,int w){
	to[++tot]=v,nxt[tot]=head[u],val[tot]=w,head[u]=tot;
}
vector<pair<int,int>>vec[M];
struct node{
	int u;
	long long dis;
	bool operator<(const node &a)const{
		return dis>a.dis;
	}
};
long long pre[N][N],dis[V];
void dij(int st){
	for(int i=1;i<=n+m;i++){
		dis[i]=0x3f3f3f3f3f3f3f3f;
	}
	priority_queue<node>q;
	q.push({st,0}),dis[st]=0;
	while(!q.empty()){
		int u=q.top().u,dist=q.top().dis;
		q.pop();
		if(dist!=dis[u])continue;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i],w=val[i];
			if(dist+w<dis[v]){
				dis[v]=dist+w;
				q.push({v,dis[v]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		pre[st][i]=dis[i]; 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>a>>t;
			add(i,n+a,t);
			add(n+a,i,t);
			vec[a].push_back({i,t}); 
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	while(q--){
		cin>>x>>y;
		long long ans=LLONG_MAX;
		for(auto i:vec[x]){
			for(auto j:vec[y]){
				ans=min(ans,i.second+j.second+pre[i.first][j.first]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
