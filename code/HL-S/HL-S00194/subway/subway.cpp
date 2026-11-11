#include<bits/stdc++.h>
#define ll long long
#define i128 __int128
using namespace std;
const int maxn =5e5+10;
int w[maxn],a[maxn],t[maxn];
struct node{
	int a,t;
};
struct node1{
	int u;ll d;
	friend bool operator<(node1 _,node1 __){
		return _.d>__.d;
	}
};
struct edge{
int v,w;
};
vector<edge>G[maxn];
vector<node>v[maxn];
ll dis[maxn];
int cnt[maxn];
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<node1>q;
   q.push({s,0});
   while(!q.empty()){
   	node1 cur=q.top();q.pop();int u=cur.u;ll d=cur.d;
   	if(dis[u]!=d)continue;
   	for(edge e:G[u]){
   		int v=e.v;ll w=e.w;
   		if(dis[v]>dis[u]+w){
   			dis[v]=dis[u]+w;
   			q.push({v,dis[v]});
		   }
	   }
   }
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){cin>>a[j]>>t[j];v[i].push_back({a[j],t[j]});cnt[a[j]]++;}
	}
	while(q--){
		int ans=0;
		int x,y;cin>>x>>y;
		ans+=w[x]+w[y];
		for(int i=1;i<=n;i++){
			for(node x:v[i]){
				int a=x.a,t=x.t;
			   G[i].push_back({a,t});
			   G[a].push_back({i,t});
			}
		}
		dijkstra(x);
		ans+=dis[y];
		cout<<ans<<"\n";
	}
	return 0;
}
