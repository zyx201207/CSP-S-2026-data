#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct node{
	int to,t;
	bool operator<(const node a)const{
		return t>a.t;
	}
};
vector<node>sub[N];
vector<int>tr[N]; 
int w[N];
int dist[N];//到第i个地铁站所需时间
bool vis[505]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){//地铁线路 
		int x;
		cin>>x;
		while(x--){
			int v,w;
			cin>>v>>w;
			sub[i].push_back({v,w});
			tr[v].push_back(i);
		}
	}
	while(q--){
		memset(dist,-1,sizeof dist);
		memset(vis,0,sizeof vis);
		int fs,fe;
		scanf("%d%d",&fs,&fe);
		priority_queue<node>pq;
		pq.push({fs,w[fs]});
		dist[fs]=w[fs];
		while(pq.size()){
			int u=pq.top().to,d=pq.top().t;
			pq.pop();
			for(int i:tr[u]){
				if(vis[i])continue;
				int now=0;
				for(node v:sub[i]){
					if(u==v.to){
						now=v.t;
						break; 
					}
				}
				for(node v:sub[i]){
					if(u==v.to)continue;
					if(dist[v.to]==-1){
						vis[i]=1;
						dist[v.to]=d+v.t+now;
						pq.push({v.to,dist[v.to]});
					}
				}
			}
		}
		printf("%d\n",dist[fe]+w[fe]);
	}
	return 0;
}
