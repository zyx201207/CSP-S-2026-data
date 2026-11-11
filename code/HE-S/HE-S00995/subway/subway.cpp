#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=500010,N=510;
int n,m,d,T,x[M],y[M],ans[M];
int w[M],k[N],dis[N+M],vis[N+M],from[N+M];
vector<int>a[N],t[N];
vector<pair<int,int> >g[N+M];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;

void dij(int st){
	for(int i=1;i<=n+m;i++) dis[i]=1e18,vis[i]=0;
	q.push({0,st});
	dis[st]=0;
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto t:g[u]){
			int v=t.first,w=t.second;
			if(dis[v]<=dis[u]+w) continue;
			dis[v]=dis[u]+w;
			from[v]=u;
			q.push({dis[v],v});
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C;
	cin>>C>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0),t[i].push_back(0);
		for(int j=1,x,y;j<=k[i];j++){
			cin>>x;a[i].push_back(x);
			cin>>y;t[i].push_back(y);
			g[i+m].push_back({x,y});
			g[x].push_back({i+m,y});
		}
	}
	for(int i=1;i<=T;i++){
		cin>>x[i]>>y[i];
		ans[i]=1e18;
	}
	for(int i=m+1;i<=n+m;i++){
		dij(i);
		for(int j=1;j<=T;j++){
			ans[j]=min(ans[j],dis[x[j]]+dis[y[j]]+w[x[j]]+w[y[j]]);
		}
	}
	for(int i=1;i<=T;i++) cout<<ans[i]<<"\n";
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/ 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

