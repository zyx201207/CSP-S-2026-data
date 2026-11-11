#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int M=2e6+10;
const int K=15;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int c,n,m,d,q;
int w[N];//地铁口到站厅 
struct edge{
	int v,w;
	int nxt;
}e[M];
int head[N],tot;
inline void add(int u,int v,int w){
	tot++;
	e[tot].v=v;
	e[tot].w=w;
	e[tot].nxt=head[u];
	head[u]=tot;
}
int cnt;
int dis[N];
priority_queue<pair<int,int> > pq;
inline void solve(int s,int ed){
	for(int i=1;i<=cnt;++i)dis[i]=INF;
	dis[s]=0;
	pq.push({dis[s],s});
	while(!pq.empty()){
		pair<int,int> cu=pq.top();
		pq.pop();
		int d=-cu.first,u=cu.second;
		if(d>dis[u])continue;
//		cout<<u<<" "<<d<<endl;
		if(u==ed)break;
		for(int it=head[u];it;it=e[it].nxt){
			int v=e[it].v,w=e[it].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({-dis[v],v});
			}
		}
	}
	while(!pq.empty())pq.pop();
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),cnt=m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i)w[i]=read();
	for(int i=1;i<=n;++i){
		cnt++;
		int k=read();
		while(k--){
			int x=read(),W=read();
			add(x,cnt,W);
			add(cnt,x,W);
		}
	}
	while(q--){
		int st=read(),ed=read();
		solve(st,ed);
		write(dis[ed]+w[st]+w[ed]); 
		putchar('\n');
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

//链式前向星 
struct edge{
	int v,w;//到v号线站台用w时间 
	int nxt;
}e[M];
int head[N],tot;
inline void add(int u,int v,int w){
	tot++;
	e[tot].v=v;
	e[tot].w=w;
	e[tot].nxt=head[u];
	head[u]=tot;
}
//链式前向星 
int h[510],nxt[N],val[N],cnt;
for(int i=1;i<=n;++i){
		int k=read();
		int lst=0;
		head[i]=cnt+1;
		while(k--){
			cnt++;
			int x=read();
			val[cnt]=x;
			nxt[lst]=cnt;
			lst=cnt;
		}
	}
*/
