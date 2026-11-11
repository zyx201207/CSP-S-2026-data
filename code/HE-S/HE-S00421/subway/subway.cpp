#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=5e5+10;
int c,n,m,d,q;
LL dist[N],w[N];
vector<PII> e[N];
bool st[N];
LL dijkstra(int S,int T){
	for(int i=1;i<=m;i++)dist[i]=4e18,st[i]=0;
	dist[S]=0;
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	heap.push({0,S});
	while(heap.size()){
		int u=heap.top().second;
		heap.pop();
		if(st[u])continue;
		st[u]=true;
		for(int i=0;i<e[u].size();i++){
			PII it=e[u][i];
			int j=it.first;
			LL dit=it.second+dist[u];
			if(dit<dist[j]){
				dist[j]=dit;
				heap.push({dit,j});
			}
		}
	}
	return dist[T];
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int u[k+1],edge[k+1];
		for(int j=1;j<=k;j++){
			cin>>u[j]>>edge[j];
			for(int t=1;t<j;t++){
				e[u[t]].push_back({u[j],edge[t]+edge[j]});
				e[u[j]].push_back({u[t],edge[t]+edge[j]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		cout<<dijkstra(a,b)+w[a]+w[b]<<'\n';
	}
	return 0;
}
