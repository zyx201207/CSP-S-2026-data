#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 6e5 + 5;
const int inf = 1e18;

int _, c, n, m, d, q, tot, ans, a[N], h[N], dis[N], diss[N];
bool vis[N];
int mp[2000][2000];

struct mb{
	int to,nxt,val;
}e[N];

void add(int u,int v,int w){
	e[++tot].to=v;
	e[tot].nxt=h[u];
	e[tot].val=w;
	h[u]=tot;
}

void dij(int x){
	for(int i=1;i<=m+n;i++){
		vis[i]=0;
		dis[i]=inf;
	}
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > qq;
	dis[x]=0;
	qq.push({0,x});
	while(!qq.empty()){
		int u=qq.top().second;
		qq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].val){
				dis[v]=dis[u]+e[i].val;
				qq.push({dis[v],v});
			}
		}
	}
}

int bfs(int x,int y){
	for(int i=1;i<=n+m;i++){
		vis[i]=0;
		diss[i]=inf;
	}
	queue<int> qq;
	qq.push(x);
	vis[x]=1;
	diss[x]=0;
	while(!qq.empty()){
		int u=qq.front();
		qq.pop();
		if(u==y)return diss[u];
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(!vis[v]){
				diss[v]=diss[u]+e[i].val;
				vis[v]=1;
				qq.push({v});
			}
		}
	}
}

void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int aa,bb;
			cin>>aa>>bb;
			add(m+i,aa,bb);
			add(aa,m+i,bb);
		}
	}
	if(9<=c&&c<=11){
		for(int i=1;i<=m;i++){
			dij(i);
			for(int j=1;j<=m;j++){
				mp[i][j]=dis[j];
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<mp[x][y]+a[x]+a[y]<<"\n"; 
		}
		return;
	}
	else if(12<=c&&c<=15){
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<bfs(x,y)+a[x]+a[y]<<"\n"; 
		}
		return;
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+a[x]+a[y]<<"\n"; 
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	_ = 1;
	while(_--){
		solve();
	}
}

