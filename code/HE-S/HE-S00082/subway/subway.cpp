#include<bits/stdc++.h>
using namespace std;
const int N=1505;
struct node{
	int v;
	long long w;
	bool operator >(const node t) const{
		return w>t.w;
	}
};
priority_queue<node,vector<node>,greater<node> > p;
int c,n,m,d,q,w[N];
long long dis[N][N];
vector<node> e[N];
bool vis[N][N];
void dij(int s){
	dis[s][s]=0;
	p.push((node){s,0});
	while(!p.empty()){
		int u = p.top().v;
		p.pop();
		if(vis[s][u]) continue;
		vis[s][u]=1;
		for(int i = 0;i<e[u].size();i++){
			int v=e[u][i].v;
			long long w=e[u][i].w;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				if(!vis[s][v]) p.push((node){v,dis[s][v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	int cnt,a;
	long long tt;
	for(int i = 1;i<=n;i++){
		cin>>cnt;
		for(int j = 1;j<=cnt;j++){
			cin>>a>>tt;
			e[m+i].push_back((node){a,tt});
			e[a].push_back((node){m+i,tt});
		}
	}
	for(int k = 1;k<=n+m;k++){
		dij(k);
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
