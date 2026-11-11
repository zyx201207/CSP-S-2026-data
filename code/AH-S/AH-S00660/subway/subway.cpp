#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
vector<int> w;
struct edge{
	int n,u,v;
};
vector<vector <edge> >a;

struct plan{
	int x,y;
};
vector<plan> p;
vector<int> dist;
vector<bool> f;

void washing(){
	for(int i=1;i<=n+m+1;i++)
		dist[i]=INT_MAX,f[i]=0;
	return;
}

void adding(int from,int to,int value){
	edge e1,e2;
	e1.u=to,e1.v=value;
	e2.u=from,e2.v=value;
	a[from].push_back(e1);
	a[to].push_back(e2);
	return ;
}

void search(int x,int y){
	if(x==y)return;//cout<<a[x].size()<<' ';
	for(int i=0;i<a[x].size();i++){
		if(f[a[x][i].u]){//cout<<"##RING##"<<x<<' '<<a[x][i].u<<endl;
			continue;}
		//printf("%d %d %d %d+%d\n",x,a[x][i].u,dist[a[x][i].u],dist[x],a[x][i].v);
		dist[a[x][i].u]=min(dist[a[x][i].u],dist[x]+a[x][i].v);
		//cout<<a[x][i].u<<' '<<y<<endl;
		f[x]=1;
		search(a[x][i].u,y);
		}
	return ;
}

int shortestWay(int x,int y){
	dist.resize(m+n+1,INT_MAX);
	f.resize(m+n+1,0);
	washing();
	//cout<<"__SETTING CHECK___";
	//for(int i=1;i<=n+m+1;i++)if(f[i])cout<<1;else cout<<0;
	
	dist[x]=0;
	search(x,y);
	
	return dist[y];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	w.resize(m+1);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	a.resize(m+n+1);
	for(int k,i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int u1=m+i,u2,v;
			scanf("%d%d",&u2,&v);
			adding(u1,u2,v);
			}
		}
	p.resize(q+1);
	for(int i=1;i<=q;i++)scanf("%d%d",&p[i].x,&p[i].y);
	
	//for(int i=1;i<=q;i++)printf("%d %d\n",p[i].x,p[i].y);
	/*
	for(int i=1;i<=a.size()-1;i++){
		for(int j=0;j<=a[i].size()-1;j++)
			cout<<i<<' '<<j<<' '<<a[i].size()<<"  "<<i<<' '<<a[i][j].v<<' '<<a[i][j].u<<endl;
		}
	cout<<"================"<<endl;*/
	
	for(int i=1;i<=q;i++)printf("%d\n",shortestWay(p[i].x,p[i].y)+w[p[i].x]+w[p[i].y]);
	
	return 0;
}
