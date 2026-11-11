#include<bits/stdc++.h>
using namespace std;
typedef long long lzx;
const int N=510;
const int M=5e5+10;
const lzx INF=1e18;
struct Edge{
	int to,nxt,w;
};
vector <Edge> e;
int tot=-1,head[N];
void add(int u,int v,int w){
	e.push_back({v,head[u],w});
	head[u]=++tot;
}
vector <int> sta[M];
int w[M],t[N][M];
int c,n,m,d,q; 
lzx dist[N][N];
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=INF;
		}
	}
	memset(head,-1,sizeof(head));
}
void dijstra(int s){
	bool vis[N]={0};
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > p;
	p.push({0,s});
	dist[s][s]=0;
	while(!p.empty()){
		int d=p.top().second;
		p.pop();
		if(vis[d]) continue;
		vis[d]=true;
		for(int i=head[d];i!=-1;i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(dist[s][d]+w<dist[s][v]){
				dist[s][v]=dist[s][d]+w;
				if(!vis[v]) p.push({dist[s][v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	init();
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int p;
			cin>>p;
			cin>>t[i][p];
			sta[p].push_back(i);
		}
	}
//	cout<<"t:\n";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<t[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	cout<<"edge:\n";
	for(int i=1;i<=m;i++){
		for(int j=0;j<sta[i].size();j++){
			for(int k=j+1;k<sta[i].size();k++){
				int u=sta[i][j],v=sta[i][k];
//				cout<<u<<' '<<v<<' '<<t[v][i]<<' '<<t[u][i]<<' '<<i<<'\n';
				add(u,v,t[u][i]+t[v][i]);
				add(v,u,t[u][i]+t[v][i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dijstra(i);
	}
//	cout<<"head:\n";
//	for(int i=1;i<=n;i++){
//		cout<<head[i]<<' ';
//	}
//	cout<<'\n';
//	cout<<"dist:\n";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dist[i][j]<<' '; 
//		}
//		cout<<'\n';
//	}
	for(int _=1;_<=q;_++){
		lzx ans=INF;
		int s1,t1;
		cin>>s1>>t1;
		for(int i=0;i<sta[s1].size();i++){
			for(int j=0;j<sta[t1].size();j++){
				int u=sta[s1][i],v=sta[t1][j];
				ans=min(ans,dist[u][v]+1ll*t[u][s1]+1ll*t[v][t1]);
			}
		}
		cout<<ans+w[s1]+w[t1]<<'\n';
	}
	return 0;
}
//16:25 
