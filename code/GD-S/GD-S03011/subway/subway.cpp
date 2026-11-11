#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=1e18;
const int N=2e4+10;
struct node{
	int to,type;
	ll val;
	bool operator<(const node &b)const{
	return val>b.val;
	}
};
ll c,n,m,d,q,w[N],dist[N][510],has[510],t[N][510];
bool vis[N][510];
vector<node>G[N];
void dij(int cur){
	priority_queue<node>q;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
		vis[i][j]=0;
		dist[i][j]=1e18;
		} 
	}
	dist[cur][0]=0;
	q.push({cur,0,0});
	while(!q.empty()){
		int u=q.top().to,type=q.top().type;q.pop();
		if(vis[u][type])continue;
		vis[u][type]=1;
		for(node v:G[u]){
			int curtype=v.type,to=v.to;
			if(curtype!=type&&type!=0){
				if(dist[to][curtype]>dist[u][type]+t[u][type]+t[u][curtype]){
					dist[to][curtype]=dist[u][type]+t[u][type]+t[u][curtype];
					q.push({to,curtype,dist[to][curtype]});
				}
			}
			else if(type==curtype){
				if(dist[to][type]>dist[u][type]){
					dist[to][type]=dist[u][type];
					q.push({to,type,dist[to][type]});
				}
			}
			else {
				dist[to][curtype]=t[u][curtype];
				q.push({to,curtype,dist[to][curtype]});
			}
		}
	}

}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a>>t[j][i];
			if(!has[i]){
				has[i]=a;
			}
			else{
				G[a].push_back({has[i],i,0});
				G[has[i]].push_back({a,i,0});
			}
		}
	}
	while(q--){
		ll x,y,ans;
		cin>>x>>y;
		dij(x);
		for(int i=1;i<=n;i++)ans=min((ll)dist[y][i]+w[x]+w[y]+t[y][i],ans);
		cout<<ans<<'\n';
	}
	return 0;
}
