#include<bits/stdc++.h>
using namespace std;
#define int long long
#define filename "subway"
const int N=1e3+5;
int c,n,m,d,q,k;
int w[N];
struct edge{
	int v,w;
};
vector<edge> e[N];

struct node{
	int x;
	int w;
	bool operator<(const node &a)const{
		return w>a.w;
	}
};
priority_queue<node> que;
bool vis[N];
int dis[N];

void dijk(int st){
	for(int i=1;i<=n;i++){
		dis[i]=1e9;
		vis[i]=0;
	}
	while(!que.empty()) que.pop();
	que.push({st,0});
	while(!que.empty()){
		int u=que.top().x;
		que.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto ed:e[u]){
			int v=ed.v,w=ed.w;
			if(w+dis[u]<dis[v]){
				dis[v]=w+dis[u];
			}
			que.push({v,dis[v]});
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cin.tie(0);
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		int last=0;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			if(last!=0){
				e[i].push_back({a,t});
				e[a].push_back({i,t});			
			}
			last=1;
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		dijk(x);
		cout<<dis[y]<<endl;
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

*/
