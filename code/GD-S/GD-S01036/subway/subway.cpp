#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int read(){
	int t;
	scanf("%d",&t);
	return t;
} 
struct Line{
	int v;
	int w;
}; 
int c,n,m,d,q;
vector<Line> e[25*maxn];
long long df[25*maxn];
int w[maxn];
void add(int u,int v,int w){
	e[u].push_back((Line){v,w});
	e[v].push_back((Line){u,w});
} 
void dfs(int u,int fa,int y){
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i].v;
		int w=e[u][i].w;
		df[v]=min(df[v],df[u]+w);
		if(v==fa) continue;
		if(v<=m && v!=y) continue;
		dfs(v,u,y);
	}
}
int main(){
	freopen("subway1.in","r",stdin);
	//freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		int w;
		w=read();
		add(i,i+m,w);
	} 
	for(int i=1;i<=n;i++){
		int k;
		k=read();
		int a,t;
		a=read(),t=read();
		add(a+((i+1)*m),a+m,t);
		for(int j=2;j<=k;j++){
			t=read();
			add(a+((i+1)*m),t+((i+1)*m),0);
			a=t;
			t=read();
			add(a+((i+1)*m),a+m,t);
		} 
	}
	while(q--){
		int x,y;
		x=read(),y=read();
		memset(df,0x3f,sizeof(df));
		df[x]=0;
		dfs(x,0,y); 
		cout<<df[y]<<endl;
	}
	return 0;
}
