#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+500+5;
ll dis[N],c,n,m,d,Q,a[N],p[505][505],x,y,vv,ww,k;
bool vis[N];
struct Node{
	ll id,d;
	friend bool operator < (Node a,Node b){
		return a.d>b.d;
	}
};
struct EDGE{
	ll to,w;
};
priority_queue<Node> q; 
vector<EDGE> g[N];
void dij(int st){
	for(int i=1;i<=n+m;i++){
		dis[i]=1e18;
		vis[i]=0;
	}
	dis[st]=0;
	q.push({st,0});
	while(!q.empty()){
		Node u=q.top();
		q.pop();
		if(vis[u.id]==1) continue;
		vis[u.id]=1;
		for(EDGE v:g[u.id]){
			if(vis[v.to]==1){
				continue;
			}
			if(dis[u.id]+v.w<dis[v.to]){
				dis[v.to]=dis[u.id]+v.w;
				q.push({v.to,dis[v.to]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>m>>n>>d>>Q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>vv>>ww;
		    g[vv].push_back({n+i,ww});
		    g[n+i].push_back({vv,ww});
		}
	}
	for(int i=1;i<=m;i++){
		dij(n+i);
		for(int j=1;j<=m;j++){
			p[i][j]=dis[n+j];
		}
	}
	while(Q--){
		ll minn=1e18;
		cin>>x>>y;
		for(EDGE v:g[x]){
			for(EDGE u:g[y]){
				minn=min(minn,p[v.to-n][u.to-n]+v.w+u.w);
		    }
		}
		cout<<minn+a[x]+a[y]<<"\n";
	}
}
