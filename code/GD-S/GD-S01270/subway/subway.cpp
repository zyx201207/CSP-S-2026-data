#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const long long INF=0xf3f3f3f3f3f3f3fLL;
const int maxm=505;
int c,n,m,d,q;
int st,en;
int a[maxm][maxm],b[maxm][maxm],k[maxm];
long long w[maxm];
struct edge{
	int id;
	long long dis;
};
vector<edge>G[maxm];
struct node{
	int id;
	long long dis;
	bool operator>(const node&other)const{
		return dis>other.dis;
	}
};
long long dist[maxm];
void dijkstra(){
	priority_queue<node,vector<node>,greater<node> >q;
	q.push({st,0});
	for(int i=0;i<maxm;i++)dist[i]=INF;
	dist[st]=0;
	while(!q.empty()){
		node t=q.top();
		q.pop();
		int u=t.id;
		if(dist[u]!=t.dis)continue;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].id;
			if(G[u][i].dis+dist[u]<dist[v]){
				dist[v]=G[u][i].dis+dist[u];
				q.push({v,dist[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>b[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
			G[a[i][j]].push_back({a[i][j+1],b[i][j]+b[i][j+1]});
			G[a[i][j+1]].push_back({a[i][j],b[i][j+1]+b[i][j]});
		}
	}
	while(q--){
		cin>>st>>en;
		dijkstra();
		cout<<w[st]+dist[en]+w[en]<<'\n';
	}
	return 0;
}
