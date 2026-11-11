#include<bits/stdc++.h>
#include<queue>
using namespace std;
vector<pair<int,int> > node[1000001];
int T,dist[1000001];
int n,m,d,q,w[1000001],k,p,t,x,y;
void build(int x,int y,int v){
	node[x].push_back(make_pair(y,v));
	node[y].push_back(make_pair(x,v));
	return ;
}
void dijks(int st){
	priority_queue<pair<int,int> > cur;
	int opt;
	bool vis[1000001];
	fill(vis,vis+n+m+11,false);
	fill(dist,dist+n+m+11,INT_MAX);
	cur.push(make_pair(0,st));
	dist[st]=0;
	while(!cur.empty()){
		opt=cur.top().second,cur.pop();
		if(vis[opt]) continue;
		vis[opt]=true;
		for(auto it:node[opt])
			if(dist[opt]+it.second<dist[it.first]){
				dist[it.first]=dist[opt]+it.second;
				cur.push(make_pair(dist[it.first],it.first));
			}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&n,&m,&d,&q);
	for(int i=1;i<=m;++i) scanf("%d",&w[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&k);
		while(k--){
			scanf("%d%d",&p,&t);
			build(p+n,i,t);
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		dijks(n+x);
		cout<<dist[n+y]+w[x]+w[y]<<endl;
	}
	return 0;
} 
