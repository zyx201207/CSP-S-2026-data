#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define int long long
#define x first
#define y second
const int mod=1e9+7;
const int N=5e2+50;
const int M=2e6+50;
const int INF=2e18;
#define IO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//站厅:1~n 地铁口:n+1~2n 
//pos[i][j]表示第i个地铁站的第j条线路的位置
//mp[i][j]表示第i条线路是第j个地铁站的第几条线路 
int c,n,m,d,q;
int pos[N][50]={};
int a[N]={};
int idx=0; 
struct edge{
	int u,v,w,nxt;
}e[M];
int head[200005]={};
int tot=0;
void addedge(int u,int v,int w){
	e[++tot]=edge{u,v,w,head[u]};
	head[u]=tot;
}
struct node{
	int u,dis;
	bool operator<(const node &cmp)const{
		return dis>cmp.dis;
	}
};
bool vis[200005]={};
int dis[200005]={};
void dijkstra(int s,int t){
	for(int i=1;i<=idx;i++){
		dis[i]=INF;
		vis[i]=0;
	}
	priority_queue<node> q;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		if(u==t){
			return;
		}
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				q.push({v,dis[v]});
			}
		} 
	}
}
int get_ans(int s,int t){
	dijkstra(s,t);
	return a[s]+dis[t]+a[t];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	IO;
	cin>>c>>m>>n>>d>>q;
	idx=2*n+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		addedge(n+i,i,a[i]);
		addedge(i,n+i,a[i]);
	}
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		int pre=-1;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			pos[x][pos[x][0]+1]=++idx;
			pos[x][0]++;
//			mp[i][x]=a[x][0]; 
			addedge(x,pos[x][pos[x][0]],y);
			addedge(pos[x][pos[x][0]],x,y);
			if(pre!=-1){
				addedge(pos[pre][pos[pre][0]],pos[x][pos[x][0]],0);
				addedge(pos[x][pos[x][0]],pos[pre][pos[pre][0]],0);
			}
			pre=x;
		}	
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<get_ans(s,t)<<endl; 
	}
	return 0;
}

