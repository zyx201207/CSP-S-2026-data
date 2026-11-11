#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct edge{
	int next;
	long long w;
};
struct node{
	int id;
	long long d;
	bool operator >(const node&b)const{
		return d>b.d;
	}
};
vector<edge>g1[N],g[505];
int n,m,q,C,d;
long long dis[505][505],w[N],a[N],t[N];
bool vis[505];
void dijkstra(int st){
	priority_queue<node,vector<node>,greater<node>> q;
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=m;i++){
		dis[st][i]=0x3f3f3f3f3f3f3f3f;
	}
	q.push({st,0});
	dis[st][st]=0;
	while(!q.empty()){
		node h=q.top();q.pop();
		int u=h.id;
		if(vis[u]==true) continue;
		vis[u]=true;
		//cout<<st<<" "<<u<<" "<<dis[st][u]<<"\n";
		for(auto e:g[u]){
			int v=e.next;
			if(dis[st][v]>dis[st][u]+e.w){
				dis[st][v]=dis[st][u]+e.w;
				q.push(node{v,dis[st][v]});
			}
		}
	}
}
long long w1[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		w1[i]=w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i]>>t[i];
			g1[a[i]].push_back(edge{i,t[i]});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto e:g1[i]){
			int u=e.next;
			for(auto e1:g1[i]){
				int v=e1.next;
				if(u==v) continue;
				g[u].push_back({v,e.w+e1.w});
			}
		}
	}

	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	for(int i=1,st,ed;i<=q;i++){
		cin>>st>>ed;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(auto e:g1[st]){
			int u=e.next;
			for(auto e1:g1[ed]){
				int v=e1.next;
				//cout<<u<<" "<<v<<" "<<st<<" "<<ed<<" "<<w1[st]<<" "<<w1[ed]<<"\n";
				ans=min(ans,dis[u][v]+e.w+e1.w+w1[st]+w1[ed]);
			}
		} 
		cout<<ans<<"\n";
	}
	return 0;
}
