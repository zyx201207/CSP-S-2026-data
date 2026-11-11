#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,fg=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*fg;
}
int c,n,m,o,p,w[500001],t[501][600001],d[1001][1001];
int cnt,h[1000001];
bool vis[500001];
struct node{
	int to,next,s;
}e[1000001];
struct pp{
	int sum,num;
	bool operator <(const pp &a)const{
		return sum>a.sum;
	}
};
void add(int x,int y,int z){
	e[++cnt].s=z;
	e[cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
void ff(int u,int v){
	memset(vis,0,sizeof(vis));
	priority_queue<pp> q;
	q.push((pp){0,u});
	while(!q.empty()){
		int x=q.top().num;
		int l=q.top().sum;
		q.pop();
		if(x==v){
			d[u][v]=d[v][u]=l;
			break;
		}
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=h[x];i;i=e[i].next){
			int y=e[i].to;
			if(!vis[y]) q.push((pp){l+e[i].s,y});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();o=read();p=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1,x;i<=n;i++){
		x=read();
		for(int j=1,y;j<=x;j++){
			y=read();
			t[i][y]=read();
		}
	}
	if(c<=11){
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				int tmp=2e9;
				for(int k=1;k<=n;k++){
					if(t[k][i]!=0&&t[k][j]!=0){
						tmp=min(tmp,t[k][i]+t[k][j]);
					}
				}
				if(tmp!=2e9) add(i,j,tmp),add(j,i,tmp);
			}
		}
		for(int i=1;i<=m;i++) d[i][i]=0;
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++) ff(i,j);
		}
		while(p--){
			int x,y;
			x=read();y=read();
			printf("%d\n",d[x][y]+w[x]+w[y]);
		}
	}
	return 0;
}
