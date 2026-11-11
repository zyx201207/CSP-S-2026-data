#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+8,M=1e6+8;
struct edge{
	long long v,w;
};
struct node{
	long long s,t,ans;
}question[N];
long long c,n,m,d,q;//线路数、站台数、站台最大线路数、询问数
long long tot;
long long a[N],ans[N];//出入站用时
bool vis[N];
vector<long long> questions[N];
vector<edge> G[M];
void add(long long u,long long v,long long w){
	G[u].push_back({v,w});
	G[v].push_back({u,w});
}
void Dijkstra(long long s){
	priority_queue<pair<long long,long long>> pq;
	memset(vis,false,sizeof vis);
	memset(ans,0x3f,sizeof ans);
	pq.push({0,s});
	ans[s]=0;
	while(!pq.empty()){
		long long u=pq.top().second;
		pq.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=true;
		for(edge i:G[u]){
			long long v=i.v,w=i.w;
			if(ans[v]>ans[u]+w){
				ans[v]=ans[u]+w;
				pq.push({-ans[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	tot=m;
	for(long long i=1;i<=m;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		long long k,u,v=++tot,w;
		cin>>k;
		while(k--){
			cin>>u>>w;
			add(u,v,w);
		}
	}
	for(long long i=1;i<=q;i++){
		long long s,t;
		cin>>s>>t;
		if(s>t){
			swap(s,t);
		}
		question[i].s=s;
		question[i].t=t;
		questions[s].push_back(i);
	}
	for(long long u=1;u<=m;u++){
		if(!questions[u].size()){
			continue;
		}
		Dijkstra(u);
		for(long long id:questions[u]){
			question[id].ans=ans[question[id].t]+a[u]+a[question[id].t];
		}
	}
	for(long long i=1;i<=q;i++){
		cout<<question[i].ans<<'\n';
	}
	return 0;
}
