#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;
const int inf=1e18;
int c,n,m,d,q;
int a[N];
int x[N];
int cnt;
struct edge{
	int v,w;
};
vector<edge> e[N];
int dis[N];
bool vis[N];

void dij(int s){
	for(int i=1;i<=n+m+5;i++) dis[i]=inf;
	for(int i=1;i<=n+m+5;i++) vis[i]=0;
	dis[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	q.push({0,s});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:e[u]){
			int v=i.v;
			int w=i.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c;
	cin>>m>>n>>d>>q;//n是地铁站数，m是地铁路线数 
	cnt=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		cnt++;
		for(int j=1;j<=k;j++){
			int t;
			cin>>x[j]>>t;
			e[x[j]].push_back({cnt,t});
			e[cnt].push_back({x[j],t});
		}
//		for(int j=1;j<k;j++) e[x[j]+n*i].push_back({x[j+1]+n*i,0});
	}
//	int cnt=5;
//	for(auto i:e[cnt]){
//		cout<<cnt<<' '<<i.v<<' '<<i.w<<'\n';
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
//		for(int i=1;i<=n;i++) cout<<dis[i]<<' ';
//		cout<<'\n';
		cout<<dis[y]+a[x]+a[y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
