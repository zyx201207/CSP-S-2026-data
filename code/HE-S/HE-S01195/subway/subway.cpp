#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ls(u) ((u)<<1)
#define rs(u) ((u)<<1|1)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pb push_back
#define min(a,b) ((a)>(b)?(b):(a))
inline int read(){
  char c=getchar();int d=0,f=0;
  while(!isdigit(c)){
	if(c=='-') f=1;c=getchar();
  }while(isdigit(c)){
	d=d*10+c-'0';c=getchar();
  }return f?-d:d;
}
void write(int x){
	if(x<0){
		putchar('-');x=-x;
	}
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
const int N=510,M=5e5+10,INF=1e18;
int dis[N][N],c,n,m,d,q,val[M];
vector<pair<int,int> > g[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	//45min 敲完了T1T2，T1一发过，T2调了2分钟，最后一个大样例跑了0.5s，很舒服 
	//密码的T3想了1h仍然是O(N^2) 还有2h，会赢吗？
	//去打T4暴力了，15pts指数级 
	//2h45min了，我服了，现在215pts，T3还是不会，有一个神秘转化的O(n^2)，似乎要什么数据结构来维护加上什么均摊分析，我不会分析我也写不出来QWQ
	//我发现神秘转化的T3加一堆分讨可过特殊性质C，我现在写了A，感觉想不出了
	//还有30min，目前100+100+48+15=263，感觉有些低 
	 
	
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++) val[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int v=read(),w=read();
			g[v].pb({i,w});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=0;k<j;k++){
				int u=g[i][j].fi,v=g[i][k].fi,w=g[i][j].se+g[i][k].se;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=dis[u][v];
//				cerr << u << ' ' << v << ' ' << w << '\n';
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x=read(),y=read(),res=INF;
		if(x==y){
			write(0);putchar('\n');
			continue;
		}
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				int u=g[x][i].fi,v=g[y][j].fi,w=g[x][i].se+g[y][j].se;
				res=min(res,dis[u][v]+w);
			}
		}
		write(res+val[x]+val[y]);putchar('\n');
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


*/

