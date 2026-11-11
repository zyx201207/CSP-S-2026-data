#include<bits/stdc++.h>
#define ll long long
#define fi(x) freopen(x".in","r",stdin)
#define fo(x) freopen(x".out","w",stdout)
#define wc(x) fi(x);fo(x)
#define F first
#define S second
using namespace std;
const int N=510,M=5e5+10;
int n,m,c,d,q;
ll w[M];
map<int,map<int,ll>> dis;
vector<ll> t[N];
bool vis[M*4],know[M];
vector<pair<ll,int>> e[4*M];
void dijkstra(int x) {
	know[x]=1;
	for(int i=1; i<=m*n+m; i++) dis[x][i]=1e18,vis[i]=0;
	dis[x][x]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
	q.push({0ll,x});
	while(!q.empty()) {
		pair<ll,int> now=q.top();
		q.pop();
		if(vis[now.S]) continue;
		vis[now.S]=1;
		for(auto i:e[now.S]) {
			if(dis[x][i.S]>now.F+i.F) {
				dis[x][i.S]=now.F+i.F;
				q.push({dis[x][i.S],i.S}); 
			}
		}
	}
	return;
}
int main() {
	wc("subway");
	//fi("subway1");
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	} 
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		int lst,now;
		ll tmp;
		for(int j=1; j<=k; j++) {
			cin>>now>>tmp;
			e[now].push_back({tmp,now+i*m});
			e[now+i*m].push_back({tmp,now});
			if(j!=1) {
				e[now+i*m].push_back({0,lst+i*m});
				e[lst+i*m].push_back({0,now+i*m});
			}
			lst=now;
		}
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		if(know[y]&&!know[x]) swap(x,y);
		if(!know[x]) dijkstra(x);
		cout<<w[x]+w[y]+dis[x][y]<<'\n';
	}
	return 0;
}

