#include<bits/stdc++.h>
#define ll long long
#define p pair<ll,int>
using namespace std;
const int N=1005;
const int M=505;

int cc;
int n,m;
int x,y;
int tot;
int d,q;
int k[M];
int b[N];
int c[N];
int val[N];
vector<int>a[M];
vector<int>t[M];
int id[N][21];
int cnt;
int head[N*42+M];
ll dist[N*45];
ll ans[N][N];
bool vis[N];

struct E{
	int to,nxt,w;
}edge[N*42+N*84+N*4+4*M];

void add(int u,int v,int w){
	++cnt;
	edge[cnt].to=v,edge[cnt].nxt=head[u],edge[cnt].w=w;
	head[u]=cnt;
}

void dijkstra(int s){
	memset(dist,0x3f3f3f3f,sizeof(dist));
	dist[s]=0LL;
	priority_queue<p,vector<p>,greater<p>>pq;
	pq.push({0LL,s});
	memset(vis,0,sizeof(vis));
	while(!pq.empty()){
		p u=pq.top();
		pq.pop();
		if(vis[u.second]) continue;
		vis[u.second]=1;
		for(int i=head[u.second];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dist[v]>dist[u.second]+edge[i].w){
				dist[v]=dist[u.second]+edge[i].w;
				pq.push({dist[v],v});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>val[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			b[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(b[i]){
			for(int j=0;j<=b[i];j++){
				id[i][j]=++tot;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(b[i]){
			for(int j=0;j<=b[i];j++){
				if(j) add(id[i][j]+tot,id[i][0]+tot,0);	
				add(id[i][j],id[i][j]+tot,val[i]);
				add(id[i][j]+tot,id[i][j],val[i]);	
			}
		}
	}
	for(int i=1;i<=n;i++){
		c[a[i][0]]++;
		add((tot<<1)+i,id[a[i][0]][c[a[i][0]]],0);
		add(id[a[i][0]][0]+tot,(tot<<1)+i,t[i][0]); 
		add((tot<<1)+i,id[a[i][0]][0]+tot,t[i][0]); 
		for(int j=1;j<k[i];j++){
			c[a[i][j]]++;
			add(id[a[i][j]][0]+tot,(tot<<1)+i,t[i][j]);
			add((tot<<1)+i,id[a[i][j]][0]+tot,t[i][j]);
			add(id[a[i][j-1]][c[a[i][j-1]]],id[a[i][j]][c[a[i][j]]],0);
		}
	}
	memset(ans,0x3f3f3f3f,sizeof(ans));
	for(int i=1;i<=m;i++){
		if(b[i]){
			dijkstra(id[i][0]);
			for(int j=1;j<=m;j++){
					ans[i][j]=min(ans[i][j],dist[id[j][0]]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<ans[x][y]<<'\n';
	}
	return 0;
}
