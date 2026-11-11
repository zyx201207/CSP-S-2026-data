#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct edge{
	ll v,w;
};
vector<edge> adj[15010];
ll n,m,d,q;
ll dis[15010],cnt[1010],f[5510][5510];
typedef pair<int,int>P;
void Dijkstra(int s){
	for(int i=1;i<=15010;i++)dis[i]=999999999999999;
	dis[s]=0;
	priority_queue<P,vector<P>,greater<P> > q;
	q.push({0,s});
	while(!q.empty()){
		P p=q.top();
		q.pop();
		ll w=p.first,u=p.second;
		//cout<<u<<' '<<w<<'\n';
		if(w!=dis[u])continue;
		for(auto i:adj[u]){
			ll ed=i.v,val=i.w;
			if(dis[ed]>dis[u]+val){
				dis[ed]=dis[u]+val;
				q.push({dis[ed],ed});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		int w;
		cin>>w;
		adj[22*i+1].push_back({22*i+2,w});
		adj[22*i+2].push_back({22*i+1,w});
	}
	for(int i=0;i<n;i++){
		int k,a,t;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a>>t;
			adj[12000+i].push_back({22*a-19+cnt[a],0});
			adj[22*a-19+cnt[a]].push_back({12000+i,0});
			adj[22*a-20].push_back({22*a-19+cnt[a],t});
			adj[22*a-19+cnt[a]].push_back({22*a-20,t});
			cnt[a]++;
		}
	}
	/*for(int i=1;i<=1000;i++){
		for(auto j:adj[i])cout<<i<<' '<<j.v<<' '<<j.w<<"|||";
		cout<<'\n';
	}*/
	while(q--){
		ll x,y;
		cin>>x>>y;
		if(f[x][y])cout<<f[x][y]<<'\n';
		else {
			Dijkstra(22*x-21);
			//for(int i=0;i<100;i++)cout<<dis[i]<<' ';
			for(int i=1;i<=500;i++)f[x][i]=f[i][x]=dis[22*i-21];
			cout<<dis[22*y-21]<<'\n';
		}
	}
	return 0;
}
