#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5.5e5+5;
const int inf=1e15;
vector<pair<int,int>> g[N];
vector<int> tra[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int c,n,m,d,Q,now=0;
int vis[N],W[N];
unordered_map<int,int> dis[505],t[505];
void dijkstra(int st){
	q.push({0,st});
	dis[st-m][st]=0;
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u]==now) continue;vis[u]=now;
		for(auto ed:g[u]){
			int v=ed.second,w=ed.first;
			if(!dis[st-m].count(v) || dis[st-m][v]>dis[st-m][u]+w){
				dis[st-m][v]=dis[st-m][u]+w;
				q.push({dis[st-m][v],v});
			}
		}
	}
}
signed main(){
	//t2
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>W[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,T;cin>>a>>T;
			t[i][a]=T;
			g[i+m].push_back({t[i][a],a});
			g[a].push_back({t[i][a],i+m});
			tra[a].push_back(i);
		}
	}
	for(int i=m+1;i<=m+n;i++){
		now++;dijkstra(i);
	}
	while(Q--){
		int x,y;cin>>x>>y;
		int ans=inf;
		for(auto tr:tra[x]){
			ans=min(ans,dis[tr][y]+t[tr][x]);
		}
		cout<<ans+W[x]+W[y]<<endl;
	}
	return 0;
} 
