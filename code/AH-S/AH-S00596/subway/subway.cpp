#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int cid,n,m,mxd,qu;
int w[M];
struct node{
	int v,w1,w2,id;
};
vector<node> g[M];
int dis[M];
struct edge{
	int d,u,idx;
	bool operator>(const edge A)const{
		return d<A.d;
	}
};
priority_queue<edge,vector<edge>,greater<edge> >q;
void dij(int st){
	memset(dis,0x3f,sizeof(dis));
	dis[st]=0;
	for(auto i:g[st]){
		dis[i.v]=min(dis[i.v],i.w1+i.w2);
		q.push({dis[i.v],i.v,i.id});
	}
	while(!q.empty()){
		edge it=q.top();
		q.pop();
		if(it.d>dis[it.u])continue;
		for(node i:g[it.u]){
			if(i.id==it.idx){
				int w=dis[it.u]-i.w1+i.w2;
				if(dis[i.v]>w){
					dis[i.v]=w;
					q.push({dis[i.v],i.v,i.id});
				}
			}else{
				int w=dis[it.u]+i.w1+i.w2;
				if(dis[i.v]>w){
					dis[i.v]=w;
					q.push({dis[i.v],i.v,i.id});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>cid>>n>>m>>mxd>>qu;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		int k0,x,y,x2,y2;
		cin>>k0;
		for(int j=1;j<=k0;j++){
			cin>>x>>y;
			if(j>1){
				g[x2].push_back({x,y2,y,i});
				g[x].push_back({x2,y,y2,i});
			}
			x2=x,y2=y;
		}
	}while(qu--){
		int l,r;
		cin>>l>>r;
		dij(l);
		cout<<dis[r]+w[l]+w[r]<<"\n";
	}
	return 0;
} 
