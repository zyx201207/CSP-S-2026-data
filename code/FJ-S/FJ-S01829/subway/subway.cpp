#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int MAXN = 10005;
const int MAXM = 50005;

struct Edge{
	int to,next;
	ll w;
}edge[MAXM];

int head[MAXN],cnt=0;

void add_edge(int u,int v,ll w){
	cnt++;
	edge[cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
}

ll dist[MAXN];
bool vis[MAXN];
int wl[MAXN];
int tl[MAXN];

struct Node{
	int id;
	ll dis;
	bool operator<(const Node&other)const{return dis<other.dis;}
};

void dijkstra(int start,int n){
	for(int i=0;i<n;i++){
		dist[i]=INF;
		vis[i]=false;
	}
	priority_queue<Node,vector<Node>,less<Node>>pq;
	pq.push({start,0});
	dist[start]=0;
	vis[start]=true;
	while(!pq.empty()){
		int u = pq.top().id;
		pq.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=head[u];i!=0;i=edge[u].next){
			int v = edge[i].next;
			int w = edge[i].w;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				pq.push({v,dist[v]});
		    }
		}
	}
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int c,n,m,d,p;
	cin >> c >> n >> m >> d >> p;
	memset(wl,0,sizeof(wl));
	memset(tl,0,sizeof(tl));
	for(int i=1;i<=m;i++){
		cin >> wl[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		vector<int>station;
		for(int j=1;j<=k;j++){
			int a,t;
			cin >> a >> t;
			station.push_back(a);
			if(j==1)continue;
			else{
				add_edge(a,station[j-1],t);
				add_edge(station[j-i],a,t);
			}
		}
	}
	vector<ll>ans;
	for(int i=0;i<p;i++){
	    int start,destination;
	    cin >> start >> destination;
	    dijkstra(start,m);
	    ans.push_back(dist[destination]+wl[start]);
	}
	for(int i=0;i<p;i++){
	    cout << ans[i] << endl;
	    cout << ans[0] << endl;
	}
	return 0;
}
