#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q,dis[1001005],inq[1001005];
struct node{
	int v,w;
};
vector<node> g[1001005];
void spfa(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(inq,0,sizeof(inq));
	queue<int> q;
	q.push(st);
	dis[st]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(node i:g[u]){
			int v=i.v,w=i.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(!inq[v]){
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		g[i].push_back({i+m,w});
		g[i+m].push_back({i,w});
	}
	for(int i=1;i<=n;i++){
		int k,w,v;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v>>w;
			g[2*m+i].push_back({v+m,w});
			g[v+m].push_back({2*m+i,w});
		}
	}
	while(Q--){
		int st,en;
		cin>>st>>en;
		spfa(st);
		printf("%d\n",dis[en]);
	}
	return 0;
}
