#include<bits/stdc++.h>
using namespace std;
const int N=505,M=1e5+5;
int c,n,m,d,q,w[N],k[N],a[N][M],t[N][M];
struct G{
	int v,no,ac;
};
vector<G>g[M];
struct node{
	int s,dis,now;
	bool operator <(const node&x)const{
		return dis>x.dis;
	}
};
vector<int>has[M];
int dis[M];
int solve(int u,int v){
	priority_queue<node>q;
	for(int i=0;i<has[u].size();i++)q.push(node{u,t[u][u],has[u][i]});
	for(int i=1;i<=m;i++)dis[i]=INT_MAX;
	dis[u]=0;
	while(!q.empty()){
		node to=q.top();
		q.pop();
		int x=to.s,y=to.dis,no=to.now;
		for(auto p:g[x]){
			if(p.v==0)continue;
			int cnt=y+t[p.no][p.ac];
			if(p.no!=no&&p.v!=v){
				cnt+=t[p.no][p.v];
			}
			if(cnt<dis[p.v]){
				if(p.v==v)cnt+=t[p.no][v];
				dis[p.v]=cnt;
				q.push(node{p.v,cnt,p.no});
			}
		}
	}
	return dis[v];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			has[a[i][j]].push_back(i);
			g[a[i][j-1]].push_back(G{a[i][j],i,j}),
			g[a[i][j]].push_back(G{a[i][j-1],i,j});
			
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<solve(u,v)+w[v]+w[u]<<'\n';
	}
}
// 60pts pls

