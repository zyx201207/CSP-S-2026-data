#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+5;
struct node{
	ll v,w;
	bool operator <(const node &rhs)const{
		if(w!=rhs.w)return w>rhs.w;
		return v<rhs.v;
	}
};
ll c,n,m,d,q,k[maxn],a[maxn][maxn],t[maxn][maxn],w[maxn],dis[maxn],vis[maxn],ans;
vector<node> g[maxn];
ll dijkstra(ll s,ll t){
	priority_queue<node> q;
	q.push({s,0});
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	while(!q.empty()){
		ll u=q.top().v;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
	//	cout<<u<<' '<<dis[u]<<'\n';
		for(node x:g[u]){
			ll v=x.v,w=x.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v])q.push({v,dis[v]});
			}
		}
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
	//		cout<<a[i][j]<<' '<<t[i][j]<<'\n';
		}
		for(int j=1;j<=k[i];j++){
			for(int w=1;w<=k[i];w++){
				if(j==w)continue;
				g[a[i][j]].push_back({a[i][w],t[i][j]+t[i][w]});
			}
		}
	}
	while(q--){
		ll s,t;
		cin>>s>>t;
		cout<<dijkstra(s,t)+w[s]+w[t]<<'\n';
	}
	return 0;
}
