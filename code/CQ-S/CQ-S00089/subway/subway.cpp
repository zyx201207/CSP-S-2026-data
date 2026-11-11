#include<bits/stdc++.h>
using namespace std;
int  c,n,m,dd,qq;
const int M=5e5+1005,N=5e2+5;
int w[M],k[N];
struct edge{
	int u,v;
	long long w;
};
long long d[M];
vector<edge> t[M];
void que(int uu,int vv){
	memset(d,0x3f3f3f,sizeof(d));
	queue<edge> q;
	d[uu]=0;
	q.push({0,uu,0});
	while(!q.empty()){
		edge u=q.front();
		q.pop();
		int p=t[u.v].size();
		for(int i=0;i<p;i++){
			edge v=t[u.v][i];
			int l=v.u,ll=v.v,lll=v.w;
			if(d[u.v]+v.w<d[v.v]){
					d[v.v]=d[u.v]+v.w;
					q.push(v);
				}
		}
	}
	printf("%lld\n",d[vv]+w[uu]+w[vv]);
}
int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&dd,&qq);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int x,y;
			scanf("%d%d",&x,&y);
			t[m+i].push_back({m+i,x,y});
			t[x].push_back({x,m+i,y});
		}
	}
	for(int i=1;i<=qq;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		que(x,y);
	}
	return 0;
}
