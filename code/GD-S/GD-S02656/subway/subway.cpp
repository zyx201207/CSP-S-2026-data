#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+5;
int c,n,m,d,q,w[N],dis[505][N];
vector<pair<int,int>> vec[N+505];
void dij(int s,int id){
	memset(dis[id],0x3f,sizeof(dis[id]));
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	dis[id][s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second,d=q.top().first;q.pop();
		if(d>dis[id][u]) continue;
		for(auto e:vec[u]){
			int v=e.first,w=e.second;
			if(dis[id][v]>dis[id][u]+w){
				dis[id][v]=dis[id][u]+w;
				q.push({dis[id][v],v});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int id=m;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int u=id+1;u<=id+n;u++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;cin>>v>>w;
			vec[u].push_back({v,w});
			vec[v].push_back({u,w});
		}
	}
	//for(int u=1;u<=id+n;u++)for(auto e:vec[u])cout<<u<<":"<<e.first<<' '<<e.second<<' ';
	for(int s=id+1;s<=id+n;s++){
		dij(s,s-id);
	}
	while(q--){
		int u,v;cin>>u>>v;
		int mn=4e18;
		for(int i=1;i<=n;i++){
			mn=min(mn,dis[i][u]+dis[i][v]);
		}
		cout<<mn+w[u]+w[v]<<'\n';
	}
	return 0;
} //0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
