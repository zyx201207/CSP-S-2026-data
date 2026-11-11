#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(long long x){
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
struct node{
	int to,ti;
};
int w[M];
vector<node> g[M+505];
long long dis[M+505];
void dj(int s,int m,int n){
	for(int i=1;i<=m+n+5;i++){
		dis[i]=LLONG_MAX;
	}
	dis[s]=0;
	priority_queue<pair<long long,int> > q;
	q.push({0,s});
	while(!q.empty()){
		long long qq=-q.top().first;
		int qqq=q.top().second;
		q.pop();
		int len=g[qqq].size();
		for(int i=0;i<len;i++){
			if(qq+g[qqq][i].ti<dis[g[qqq][i].to]){
				dis[g[qqq][i].to]=qq+g[qqq][i].ti;
				q.push({-dis[g[qqq][i].to],g[qqq][i].to});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,Q;
	c=read();
	n=read();
	m=read();
	d=read();
	Q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int j=1;j<=n;j++){
		int k;
		k=read();
		for(int i=1;i<=k;i++){
			int a,t;
			a=read();
			t=read();
			g[a].push_back({m+j,t});
			g[m+j].push_back({a,t});
		}
	}
	while(Q--){
		int x,y;
		x=read();
		y=read();
		dj(x,m,n);
		write(dis[y]+w[x]+w[y]);
		putchar('\n');
	}
	return 0;
}
