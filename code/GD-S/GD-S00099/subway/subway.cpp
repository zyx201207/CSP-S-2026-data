#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5,M=500;
int c,n,m,d,q;
int head[2*N+5],nxt[2*N+5],to[2*N+5],weight[2*N+5],idx;
int dis[N+5],col[N+5],last[N+5];
int etl[N+5],ltf[20][N+5];
void add(int u,int v,int w){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
	weight[idx]=w;
}
void dijkstra(int s,int e){
	fill(dis+1,dis+N+1,1e9);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	dis[s]=0;
	pq.push({0,s});
	last[s]=s;
	for(int i=head[s];i;i=nxt[i]){
		int v=to[i],w=weight[i];
		dis[v]=w;
	}
	while(!pq.empty()){
		auto[d,u]=pq.top();
		pq.pop();
		if(d!=dis[u]) continue;
		if(u==e) return ;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i],w=weight[i];
			if(ltf[col[last[u]]][v]>0){
				if(dis[u]<dis[v]){
					dis[v]=dis[u];
					last[v]=u;
					pq.push({dis[v],v});
				}
			}else{
				if(dis[u]+ltf[col[u]][u]+ltf[col[v]][u]+w<dis[v]){
					dis[v]=dis[u]+ltf[col[u]][v]+ltf[col[v]][u]+w;
					last[v]=u;
					pq.push({dis[v],v});
				}
			}
		}
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>etl[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		int start,end,tv,tc;
		vector<int> tmp;
		for(int j=1;j<=k;j++){
			cin>>tv>>tc;
			if(!col[tv]){
				col[tv]=i;
			}
			ltf[i][tv]=tc;
			if(j==1) start=tv;
			if(j==k) end=tv;
			tmp.push_back(tv);
		}
		for(int j=0;j<k-1;j++) add(tmp[j],tmp[j+1],ltf[col[start]][start]);
		for(int j=k-1;j>2;j--) add(tmp[j],tmp[j-1],ltf[col[end]][end]);
	}
	int rx,ry;
	for(int i=1;i<=q;i++){
		cin>>rx>>ry;
		dijkstra(rx,ry);
		cout<<dis[ry]+etl[rx]+etl[ry]+ltf[col[rx]][rx]+ltf[col[ry]][ry]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
