#include<bits/stdc++.h>

using namespace std;

const int N=510;
int w[N],k[N],a[N][N],t[N][N];
int x[N],y[N];
bool vis[N];
int dis[N];
struct Node{
	int v;
	int d;
};
vector<Node>ed[N];

struct E{
	int x,w;
	bool operator >(const E &o)const{
		return o.w>w;
	} 
};
void dj(int s){
	memset(vis,false,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	priority_queue<E,vector<E>,greater<E>>pq;
	pq.push({0,s});
	while(!pq.empty()){
		int u=pq.top().x;
		pq.pop(); 
		if(vis[u])continue;
		vis[u]=true;
		for(auto y:ed[u]){
			if(dis[y]>dis[u]+w[u])
			dis[y]=dis[u]+w[u];
		}
	}
} 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			ed[i].push_back({a[i][j],t[i][j]});	
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		dj(x[i]);
		cout<<w[x[i]]+w[y[i]]+dis[y[i]];
	}
	
	return 0;
}
