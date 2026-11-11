#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+1000;
int c,n,m,d,q,K,tot,w[N],k[510],h[N],dis[2010][2010],ans[N];
bool vis[N];
vector<int> a[510],t[510];
struct node{
	int x,y,w,nxt;
}e[N*2]; 
void add(int x,int y,int w){
	e[++tot].x=x;
	e[tot].y=y;
	e[tot].w=w;
	e[tot].nxt=h[x];
	h[x]=tot;
}
void dijstra(int p){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	fill(vis,vis+1+n+m,0);
	fill(dis[p],dis[p]+1+n+m,1e18);
	dis[p][p]=0;
	q.push({0,p});
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=h[x],y;i;i=e[i].nxt){
			y=e[i].y;
			if(dis[p][y]>dis[p][x]+e[i].w){
				dis[p][y]=dis[p][x]+e[i].w;
				q.push({dis[p][y],y});
			}
		}
	}
	return ;
}
int bfs(int X,int Y){
	queue<int> q;
	q.push(X);
	fill(vis,vis+1+n+m,0);
	fill(ans,ans+1+n+m,0);
	while(!q.empty()){
		int x=q.front();
		//cout<<"?"<<'\n';
		if(x==Y) break;
		q.pop();
		vis[x]=1;
		for(int i=h[x],y;i;i=e[i].nxt){
			y=e[i].y;
			if(vis[y]) continue;
			ans[y]=ans[x]+1;
			q.push(y);
		}
	}
	//for(int i=1;i<=n+m;i++) cout<<ans[i]<<" ";
	return ans[Y];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i]; 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		K+=k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1,A,T;j<=k[i];j++){
			cin>>A>>T;
			a[i].push_back(A);
			t[i].push_back(T);
			add(m+i,a[i][j],t[i][j]);
			add(a[i][j],m+i,t[i][j]);
		}
	}
	if(K<=1000){// 跑1000次dij，再查询 ok
		for(int i=1;i<=m;i++) dijstra(i);
		int x,y;
		while(q--){
			cin>>x>>y;
			cout<<dis[x][y]+w[x]+w[y]<<'\n';
		}
		return 0;
	}
	if(K<=20000 && q<=2000){
		int x,y;
		while(q--){
			cin>>x>>y;
			cout<<bfs(x,y)*e[1].w+w[x]+w[y]<<'\n';
		}
	}
	return 0;
}
/*
T2 
图论
无向边，无边权
貌似是一种把边权强行按到点权上的操作
那不就是将两点i,j之间的边权设为两段了吗
把边权拼回来，再跑一下dijstar就完事了 
不行，询问次数太多了，应该要跑SPFA，早上怎么不学一下啊！ 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
我记得好像是这么写的…… 
不对！！！！
地铁站有5e5个！！ 
	
实现：
 关键在怎么搞边权 
 考虑建中转点，只需要n个； 
 建图的问题搞定了，现在要解决如何快速查询 
0 2 5 20 3
4 1 9 2 5
3 1 2 2 2 4 2
3 2 2 3 2 5 2
1 2
1 3
4 5
*/
