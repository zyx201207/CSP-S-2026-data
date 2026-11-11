#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,qu,w[M],k[N],x,y,dist[5005][5005],vis[M];
struct node{int a,t;}t;
struct str{int id,dis;};
vector<node> v[N];
vector<str> edge[N];
priority_queue<str> q;
bool operator<(str a,str b){return a.dis>b.dis;}
void distjia(int s){
	for(int i=1;i<=m;i++)dist[s][i]=1e18,vis[i]=0;
	dist[s][s]=0;
	q.push({s,0});
	while(!q.empty()){
		str x=q.top();
		q.pop();
		if(vis[x.id])continue;
		vis[x.id]=1;
		for(auto tx:edge[x.id]){
			if(dist[s][x.id]+tx.dis<dist[s][tx.id]){
			    dist[s][tx.id]=dist[s][x.id]+tx.dis;
			    q.push({tx.id,dist[s][tx.id]});
			}
		}
	} 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>qu;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
    	cin>>k[i];
    	for(int j=1;j<=k[i];j++){
    		cin>>t.a>>t.t;
    		v[i].push_back(t);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			for(int u=j+1;u<k[i];u++){
				edge[v[i][j].a].push_back({v[i][u].a,v[i][j].t+v[i][u].t});
				edge[v[i][u].a].push_back({v[i][j].a,v[i][j].t+v[i][u].t});
			}
		}
	}
	for(int i=1;i<=m;i++)distjia(i);
	for(int i=1;i<=qu;i++){
		cin>>x>>y;
		cout<<dist[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
//这个感觉很像最短路
//没事我都有个T1了怕什么 
//完蛋了半天没读懂题目 
//nicer!!!17:45拿下T2 44分 
