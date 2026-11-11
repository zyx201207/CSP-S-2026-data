#include <bits/stdc++.h>
#define int long long
#define endl putchar('\n')
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int read(){
	char c=getchar();
	int x=0;bool flag=false;
	while(c>'9' || c<'0'){
		if(c=='-') flag=true;
		c=getchar();
	}
	while(c<='9' && c>='0'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return flag ? -x : x;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=505, M=1e3+5;
struct edge{
	int u, v, len, pre;
}e[M<<2];
int p[M<<1], idx=0;
void add(int u, int v, int len){
	idx++;
	e[idx].u=u;
	e[idx].v=v;
	e[idx].len=len;
	e[idx].pre=p[u];
	p[u]=idx;
}
struct node{
	int d, u;
	friend bool operator < (node x, node y){
		return x.d>y.d;
	}
};
int c, n, m, d, q;
int dist[M<<1];bool flag[M<<1];
int ans[M][M];
void dij(int s){
	for(int i=1;i<=(m<<1);i++) dist[i]=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=(m<<1);i++) flag[i]=false;
	priority_queue<node> q;q.push({0,s});dist[s]=0;
	while(!q.empty()){
		node t=q.top();q.pop();
		int u=t.u;
		if(flag[u]) continue;
		flag[u]=true;
		for(int i=p[u];i;i=e[i].pre){
			int v=e[i].v, len=e[i].len;
			if(dist[v]>dist[u]+len){
				dist[v]=dist[u]+len;
				q.push({dist[v],v});
			}
		}
	}
	for(int i=1;i<=m;i++) ans[s][i]=dist[i];
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		int w=read();
		add(i,i+m,w);
		add(i+m,i,w);
	}
	for(int i=1;i<=n;i++){
		int k=read(), a=0, t=0;
		for(int j=1;j<=k;j++){
			a=read();t=read();
			add(a+m,(i)*m,t);
			add((i)*m,a+m,t);
		}
	}
	for(int i=1;i<=m;i++){
		dij(i);
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cerr<<ans[i][j]<<' ';
//		}
//		cerr<<'\n';
//	}
	while(q--){
		int x=read(), y=read();
		write(ans[x][y]);endl;
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
