#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int input();
void print(int x);
constexpr int N=3e5+1,M=5e5+1;
vector <int> road[N];
int head[N],nxt[M<<1],to[M<<1],val[M<<1],tot;
int w[N];
int t[501][N];
int dis[N];
bool vis[N];
inline void add(int u,int v,int w){
	nxt[tot]=head[u];
	to[tot]=v;
	val[tot]=w;
	head[u]=tot++;
}
inline void dijkstra(int s){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue <pair <int,int>,vector <pair <int,int>>,greater <pair <int,int>>> q;
	q.push({0,s});
	dis[s]=0;
	while (!q.empty()){
		int d=q.top().first,u=q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (int i = head[u];~i;i=nxt[i]){
			int v=to[i],w=val[i];
			if (dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[u]+w,v});
			}
		} 
	}
}
signed main(void){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof head);
	int c=input(),n=input(),m=input(),d=input(),p=input();
	for (int i = 1;i<=m;i++) w[i]=input();
	for (int i = 1;i<=n;i++){
		int k=input(),lst=-1;
		while (k--){
			int u=input();
			if (lst!=-1){
				add(i*m+lst,i*m+u,0);
				add(i*m+u,i*m+lst,0);
			}
			road[u].push_back(i);
			t[i][u]=input();
			lst=u;
		}
	}
	for (int i = 1;i<=m;i++){
		for (int j = 0;j<road[i].size();j++){
			for (int k = j+1;k<road[i].size();k++){
				add(road[i][j]*m+i,road[i][k]*m+i,t[road[i][j]][i]+t[road[i][k]][i]);
				add(road[i][k]*m+i,road[i][j]*m+i,t[road[i][j]][i]+t[road[i][k]][i]);
			}
		} 
	}
	while (p--){
		int x=input(),y=input(),ans=0x3f3f3f3f3f3f3f3f;
		for (int i = 0;i<road[x].size();i++){
			int u=road[x][i]*m+x;
			dijkstra(u);
			for (int j = m+y;j<=m*(n+1);j+=m){
				if (dis[j]!=0x3f3f3f3f3f3f3f3f){
					int roadid=(j-y)/m;
					ans=min(ans,w[x]+w[y]+dis[j]+t[road[x][i]][x]+t[roadid][y]);
				}
			}
		}
		print(ans),puts("");
	}
	return 0;
}
inline int input(){
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void print(int x){
	if (x<0){
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
