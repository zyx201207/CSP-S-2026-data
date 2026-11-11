#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
};
vector<node> g[10200007];
int c,n,m,dd,Q,w[500005],d[10200007];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void dij(int st){
	memset(d,0x3f,sizeof(d));
	q.push({0,st});
	d[st]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v,nw=g[u][i].w;
			if(d[v]>d[u]+nw){
				d[v]=d[u]+nw;
				q.push({d[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	int la=0;
	for(int i=1;i<=n;i++){
		int kk,t;
		cin>>kk;
		cin>>la>>t;
		g[la].push_back(node{i*m+la,t});
		g[i*m+la].push_back(node{la,t});
		for(int j=2;j<=kk;j++){
			int a;
			cin>>a>>t;
			g[i*m+la].push_back(node{i*m+a,0});
			g[i*m+a].push_back(node{i*m+la,0});
			g[i*m+a].push_back(node{a,t});
			g[a].push_back(node{i*m+a,t});
			la=a;
		}
	}
	for(int i=1;i<=Q;i++){
		int st,en;
		cin>>st>>en;
		dij(st);
		cout<<d[en]+w[st]+w[en]<<"\n";
	}
	return 0;
}
