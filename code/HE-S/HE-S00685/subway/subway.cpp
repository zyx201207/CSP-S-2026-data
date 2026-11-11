#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ll long long
#define fori(a,b) for(int i=a;i<=b;i++)
#define forj(a,b) for(int j=a;j<=b;j++)
using namespace std;
struct Node{
	int v,dist;
	bool operator <(const Node&x)const{
		return dist>x.dist;
	}
};
int c,n,m,d,t,w[500050],dist[500050],vis[500050];
vector<Node> e[501];
priority_queue<Node> q;
void dij(int x,int y){
	memset(vis,0,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));
	q.push({x,0});
	dist[x]=0;
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
//		if(vis[u]) continue;
//		vis[u]=1;
		for(auto i:e[u]){
//			cout<<'!';
			int v=i.v,w=i.dist;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push({v,dist[v]});
			}
		}
	}
	cout<<dist[y]+w[x]+w[y]<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>t;
	fori(1,m){
		cin>>w[i];
	}
	fori(1,n){
		int rub;
		cin>>rub;
		int x,y,z1,z2;
		cin>>x>>z1>>y>>z2;
		e[x].push_back({y,z1+z2});
		e[y].push_back({x,z1+z2});
	}
	fori(1,t){
		int x,y;
		cin>>x>>y;
		dij(x,y);
	}
	return 0;
}
