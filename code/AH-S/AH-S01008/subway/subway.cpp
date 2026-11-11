#include<bits/stdc++.h>
using namespace std;
int n,m,d,p,w[500005],h[500005],l[505],x,y,x1,y1,ect,c,vis[500005];
struct edge{
	int v,p,nm,w1,w2;
}e[25000005];
void add(int u,int v,int w1,int w2,int mm){
	e[++ect].v=v;
	e[ect].nm=mm;
	e[ect].w1=w1;
	e[ect].w2=w2;
	e[ect].p=h[u];
	h[u]=ect;
}
int dfs(int u,int sum,int gl,int nm,int w){
	if(u==gl){
		return sum+w;
	}
	if(h[u]==0){
		return INT_MAX;
	}
	vis[u]=1;
	int tp1=INT_MAX;
	for(int i=h[u];i;i=e[i].p){
		if(vis[e[i].v]==0){
			if(e[i].nm!=nm){
				tp1=min(dfs(e[i].v,sum+e[i].w1+w,gl,e[i].nm,e[i].w2),tp1);
			}
			else{
				tp1=min(dfs(e[i].v,sum,gl,nm,e[i].w2),tp1);
			}
		}
	}
	vis[u]=0;
	return tp1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	cin>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>l[i];
		cin>>x>>y;
		for(int j=2;j<=l[i];j++){
			cin>>x1>>y1;
			add(x,x1,y,y1,i);
			add(x1,x,y1,y,i);
			x=x1;
			y=y1;
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x>>y;
		cout<<dfs(x,0,y,0,0)+w[x]+w[y]<<"\n";
	}
	
	return 0;
}
//63
//64
//65
//66
//67676767
