#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct edge{
	int u,v;
};
vector<edge> e[N];
struct node{
	int v,val;
	friend bool operator >(node a,node b){
		return a.val >b.val ;
	}
};
priority_queue<node,vector<node>,greater<node> > q;
bool vis[N];
int dis[1005][30005];
int c,n,m,d,qu;
void dijkstra(int s){
	while(!q.empty()) q.pop();
	q.push({s,0});
	memset(vis,0,sizeof(vis));
	int ns=s;
	if(c>=9&&c<=11);
	else ns=0;
	memset(dis[ns],0x3f,sizeof(dis[ns]));
	dis[ns][s]=0;
	while(!q.empty()){
		int v=q.top().v;
		q.pop();
		if(vis[v]==true) continue;
		vis[v]=true;
		for(edge x:e[v]){
			int u=x.u,w=x.v;
			if(dis[ns][v]+w<dis[ns][u]){
				dis[ns][u]=dis[ns][v]+w;
				q.push({u,dis[ns][u]});
			}
		}  
	}
}

int tim[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++){
		cin>>tim[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int s,t;
			cin>>s>>t;
			e[m+i].push_back({s,t});
			e[s].push_back({m+i,t});
		}
	} 
	if(c<=11&&c>=9){
		for(int i=1;i<=m;i++){
			dijkstra(i);
		}
	}
	
	while(qu--){
		int s,t;
		cin>>s>>t;
		if(c<=11&&c>=9){
			cout<<dis[s][t]+tim[s]+tim[t]<<endl;
		}
		else{
			dijkstra(s);
			cout<<dis[0][t]+tim[s]+tim[t]<<endl;
		}
	}
	return 0;
}
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3*/
//   亡      亡 
//   口      口
// 月贝凡  月贝凡 
//chenchaxin忘写freopen换我不挂分！！！
//chenchaxin忘写freopen换我不挂分！！！
//chenchaxin忘写freopen换我不挂分！！！
//chenchaxin忘写freopen换我不挂分！！！
//chenchaxin忘写freopen换我不挂分！！！（无意义发癫） 
