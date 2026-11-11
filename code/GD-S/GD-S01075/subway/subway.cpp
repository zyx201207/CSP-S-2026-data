#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=5e2+5;
int c,n,m,D,q;
ll w[N],d[M][M];
vector<pair<int,ll>> tor[N];
vector<pair<int,ll>> vec[M];
void dijkstra(int s){
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> Q;
	Q.push({0,s});
	d[s][s]=0;
	while(!Q.empty()){
		pair<ll,int> cur=Q.top();
		Q.pop();
		ll cd=cur.first;
		int u=cur.second;
		if(cd>d[s][u]) continue;
		for(pair<int,ll> p:vec[u]){
			int v=p.first;
			ll w=p.second;
			if(d[s][v]>d[s][u]+w){
				d[s][v]=d[s][u]+w;
				Q.push({d[s][v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(d,0x3f,sizeof(d));
	cin>>c>>m>>n>>D>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1,k;i<=m;i++){
		cin>>k;
		for(int j=1,x;j<=k;j++){
			ll v;
			cin>>x>>v;
			tor[x].push_back({i,v});
		}
	}
	for(int u=1;u<=n;u++){
		for(int i=0;i<(int)tor[u].size();i++){
			for(int j=i+1;j<(int)tor[u].size();j++){
				int v1=tor[u][i].first,v2=tor[u][j].first;
				ll w1=tor[u][i].second,w2=tor[u][j].second;
				vec[v1].push_back({v2,w1+w2});
				vec[v2].push_back({v1,w1+w2});
			}
		}
	}
	for(int i=1;i<=m;i++) dijkstra(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=0x3f3f3f3f3f3f3f3fLL;
		for(pair<int,ll> p1:tor[x]){
			for(pair<int,ll> p2:tor[y]){
				ans=min(ans,w[x]+w[y]+p1.second+p2.second+d[p1.first][p2.first]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
