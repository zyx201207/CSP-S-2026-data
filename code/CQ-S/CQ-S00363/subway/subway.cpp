#include<bits/stdc++.h>
using namespace std;
void fast(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
#define int long long
const int N=505;
const int M=5e5+5;
int c,n,m,D,q;
int w[M];
struct sub{
	int v,w;
};
vector<sub> g[N];
struct edge{
	int v,w;
};
vector<edge> d[M];
const int INF=1e18;
struct node{
	int dis,u;
	bool operator<(const node& x)const{
		return x.dis<dis;
	}
};
int dis[M];
bool vis[M];
int dis2[N];
void Dijkstra(int s){
	for(int i=1;i<=m;i++){
		dis[i]=INF;
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		dis2[i]=INF;
	}
	priority_queue<node> q;
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(edge i:d[u]){
			if(dis2[i.v]>dis[u]+i.w){
				dis2[i.v]=dis[u]+i.w;
			}
			for(sub j:g[i.v]){
				if(dis[j.v]>dis2[i.v]+j.w){
					dis[j.v]=dis2[i.v]+j.w;
					q.push({dis[j.v],j.v});
				}
			}
		}
	}
}
void B(int T){
	while(q--){
		int s,t;
		cin>>s>>t;
		for(int i=1;i<=m;i++){
			dis[i]=INF;
			vis[i]=0;
		}
		for(int i=1;i<=n;i++){
			dis2[i]=INF;
		}
		queue<int> q;
		q.push(s);
		dis[s]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(vis[u]){
				continue;
			}
			vis[u]=1;
			for(edge i:d[u]){
				if(dis2[i.v]>dis[u]+i.w){
					dis2[i.v]=dis[u]+i.w;
					for(sub j:g[i.v]){
						if(dis[j.v]>dis2[i.v]+j.w){
							dis[j.v]=dis2[i.v]+j.w;
							q.push(j.v);
						}
					}
				}
			}
		}
		cout<<w[s]+dis[t]+w[t]<<"\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	fast();
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int T=0;
	bool fb=1;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[i].push_back({a,t});
			d[a].push_back({i,t});
			if(T==0){
				T=t;
			}
			else{
				if(T!=t){
					fb=0;
				}
			}
		}
	}
	if(fb){
		B(T);
	}
	else{
		while(q--){
			int s,t;
			cin>>s>>t;
			Dijkstra(s);
			cout<<w[s]+dis[t]+w[t]<<"\n";
		}
	}
	return 0;
}

