#include<bits/stdc++.h>
using namespace std;

#define int __int128
const int N=2e6+2;
struct edge{
	int to,w;
	edge(){}
	edge(int T,int W){
		to=T,w=W;
	}
};
vector<edge> graph[N];
void add_edge(int u,int v,int w){
	graph[u].emplace_back(v,w);
}

const int INF=1e36+7;
int dist[N],sum[N];
void dijkstra(int s,int n){
	fill(dist+1,dist+n+1,INF);
	fill(sum+1,sum+n+1,0);
	priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> heap;
	dist[s]=0;
	heap.emplace(dist[s],s);
	while(!heap.empty()){
		auto t=heap.top();
		heap.pop();
		int d=t.first,v=t.second;
		if(d>dist[v]){
			continue;
		}
		for(const auto &e:graph[v]){
			if(dist[e.to]>d+e.w){
				dist[e.to]=d+e.w;
				sum[e.to]+=1;
				heap.emplace(dist[e.to],e.to);
			}
			else if(dist[e.to]==d+e.w){
				sum[e.to]+=1;
			}
		}
	}
}

void init(int n){
	for(int i=1;i<=n;i++){
		graph[i].clear();
	}
}
#undef int

#define int long long
int cdt[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		init(n);
		for(int i=1;i<=n;i++){
			cin>>cdt[i];
			for(int j=1;j<i;j++){
				if(cdt[i]-cdt[j]<=d){
					add_edge(j,i,1);
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			dijkstra(i,n);
			for(int i=1;i<=n;i++){
				cnt+=(sum[i]==2);
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}

