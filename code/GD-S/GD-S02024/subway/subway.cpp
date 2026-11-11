#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
using namespace std;
const int kmaxN = 5e5 + 510;
const ll inf = 1e17;
int c,m,n,d,q,w[kmaxN],st,ed;
ll dis[2000][2000]; 
bool vis[2000][2000];
vector<pii> g[kmaxN]; 
bool fff = 0;
ll TTT;
priority_queue<pii,vector<pii>,greater<pii> > qq; 
void dij(int st){
	for(int j = 1;j <= n+m;j++){
		dis[st][j] = inf;
		vis[st][j] = 0;	
	}
	dis[st][st] = 0;
	qq.push(make_pair(0ll,st));
	while(!qq.empty()){
		ll d = qq.top().first;
		int u = qq.top().second;
		qq.pop();
		if(vis[st][u]) continue;
		vis[st][u] = 1;
		for(pii nx : g[u]){
			int v = nx.second;
			ll vall = nx.first;
			if(dis[st][u] + vall < dis[st][v]){
				dis[st][v] =dis[st][u] + vall;
				qq.push(make_pair(dis[st][u] + vall,v));
			}
		}
	}
} 
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) cin>>w[i];
	for(int i = 1,k = 0;i <= n;i++){
		cin>>k;
		for(int j = 1,val = 0,to = 0;j <= k;j++){
			cin>>to>>val;
			if(i == 1 && j == 1) TTT = val;
			if(val != TTT)fff = 1;
			g[i+m].push_back({val,to});
			g[to].push_back({val,i+m});
		}
	}
	if(!fff){
		qq.push(make_pair(0ll,1));
		while(!qq.empty()){
			ll d = qq.top().first;
			int u = qq.top().second;
			qq.pop();
			if(vis[1][u]) continue;
			vis[1][u] = 1;
			for(pii nx : g[u]){
				int v = nx.second;
				ll vall = 1ll;
				if(dis[1][u] + vall < dis[1][v]){
					dis[1][v] =dis[1][u] + vall;
					qq.push(make_pair(dis[st][u] + vall,v));
				}
			}
		}
		while(q--){
			cin>>st>>ed;
			if(dis[1][st] < dis[1][ed]) swap(dis[1][st] , dis[1][ed]);
			cout<<(dis[1][st] - dis[1][ed]) * TTT + w[st] + w[ed]<<'\n';
		}
	}else{
		//cout<<111;
		for(int i = 1;i <= n;i++){
			dij(i);
		}
		
		while(q--){
			cin>>st>>ed;
			cout<<dis[st][ed] + w[st] + w[ed]<<'\n';
		}		
	}

	return 0;
} 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
