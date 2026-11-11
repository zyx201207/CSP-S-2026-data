#include<bits/stdc++.h>
using namespace std;
const int N=10510;
struct edge{
	long long u,w;
};
struct node{
	long long u,dis;
	operator <(const node x)const{
		return dis<x.dis;
	}
};
int c,n,m,d,p;
vector<edge>g[N];
long long dis[N];
long long a[N];
int x,y;
void di(){
	for(int i=1;i<=m+n;i++){
		dis[i]=1e18;
	}
	priority_queue<node>q;
	dis[x]=a[x];
	q.push({x,a[x]});
	while(!q.empty()){
		auto t=q.top();
		int u=t.u;
		q.pop();
		for(auto e:g[u]){
			int v=e.u;
			long long w=e.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,w;
			cin>>u>>w;
			g[m+i].push_back({u,w});
			g[u].push_back({m+i,w});
		}
	}
	while(p--){
		cin>>x>>y;
		di();
		cout<<dis[y]+a[y]<<endl;
	}
	return 0;
}

