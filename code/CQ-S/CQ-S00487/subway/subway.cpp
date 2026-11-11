#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+1005;
const ll inf=LLONG_MAX/2;
int c,n,m,d,q;
int w[N];
struct node{
	int v;
	ll w;
};
vector<node>graph[N];
ll ans[3005][3005];
ll dis[N];
bool f[N];
int cnt;
void dijkstra(int zhan){
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
	for(int i=1;i<=cnt;i++){
		dis[i]=inf;
		f[i]=0;
	}
	dis[zhan]=0;
	pq.push({0,zhan});
	while(pq.size()){
		auto cur=pq.top();
		pq.pop();
		int u=cur.second;
		if(f[u])continue;
		f[u]=1;
		for(auto qwq:graph[u]){
			int id=qwq.v;
			ll len=qwq.w;
			if(dis[id]>dis[u]+len){
				dis[id]=dis[u]+len;
				pq.push({dis[id],id});
			}
		}
	}
	for(int i=1;i<=m;i++){
		ans[zhan][i]=dis[i];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	cnt=2*m;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		graph[i].push_back({i+m,w[i]});
		graph[i+m].push_back({i,w[i]});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int last=0;
		for(int j=1;j<=k;j++){
			cnt++;
			int a,t;
			cin>>a>>t;
			graph[cnt].push_back({a+m,t});
			graph[a+m].push_back({cnt,t});
			if(last){
				graph[cnt].push_back({last,0});
				graph[last].push_back({cnt,0});
			}
			last=cnt;
		}
	}
	for(int i=1;i<=m;i++){
		dijkstra(i);
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<ans[a][b]<<"\n";
	}
	return 0;
}
