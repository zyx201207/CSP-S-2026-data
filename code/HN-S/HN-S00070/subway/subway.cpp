#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
const int M=1e6+10;
const int inf=1e18;
int h[N],to[M],nxt[M],l[M],r[M],val[M];
int cnt;
int c,n,m,d,qq;
int dis[N][N];
int s[N];
struct Node{
	int id,v,z,s;//v,w,到达地铁路线，反悔数值 
	friend bool operator<(Node x,Node y){
		return x.v>y.v;
	}
};
void add(int u,int v,int ut,int vt,int i){
	to[++cnt]=v;
	l[cnt]=ut;
	r[cnt]=vt;
	val[cnt]=i;
	nxt[cnt]=h[u];
	h[u]=cnt;
}
void Dijkstra(int st){
	priority_queue<Node>q;
	q.push({st,0,0,0});
	while(!q.empty()){
		Node u=q.top();q.pop();
		for(int i=h[u.id];i;i=nxt[i]){
			int v=to[i],w=r[i]+l[i];
			if(u.z==val[i])w=w-l[i]-u.s;
			if(u.v+w<dis[st][v]){
				dis[st][v]=u.v+w;
				q.push({v,u.v+w,val[i],r[i]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)cin>>s[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		int lu,lt;
		for(int j=1;j<=len;j++){
			int u,t;
			cin>>u>>t;
			if(i==1){
				lu=u,lt=t;
				continue;
			}add(lu,u,lt,t,i);
			add(u,lu,t,lt,i);
		}
	}while(qq--){
		int x,y;
		cin>>x>>y;
		if(dis[x][y]==inf)Dijkstra(x);
		cout<<dis[x][y]+s[x]+s[y]<<endl;
	}
	return 0;
}

