#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,p,h,g,ans;
int w[100000],a[10000];
int k,x,t[100000];
struct node{
	int u,v,dis;
};
bool oerator < (node x,node y){
	return x.dis>y.dis;
}
priority_queue <node> q[1000];
int find(int x){
	if(a[x]!=x) return a[x]=find(a[x]);
	return x;
}
void kruskal(){
	int u=q.top().u;
	int v=q.top().v;
	int dis=q.top().dis;
	q.pop();
	int fu=find(u);
	int fv=find(v);
	if(fu==fv) continue;
	fu=fv;
	if(find(h)==find(g)) ans+=q.top().dis+w[h]+w[g];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c&n&m&d&p);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
		a[i]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&x);
			scanf("%d",&t[x]);
			q.push().dis=t[x];
		}
	}
	for(int i=1;i<=p;i++){
		scanf("%d%d",&h&g);
		for(int j=h;j<=g;j++){
			q.push().u=h;
			q.push().v=g;
		}
		kruskal();
		printf("%d",ans);
	}
	return 0;
}
