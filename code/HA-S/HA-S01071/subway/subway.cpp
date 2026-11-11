#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int read() {
	int x;scanf("%d",&x);return x;
}
struct {
	int y,v,nxt;
}e[N*2];
int Link[N],len;
void add(int x,int y,int v) {
	e[++len]={y,v,Link[x]};
	Link[x]=len;
}
int d[510],vis[510];
void dij(int s) {
	priority_queue<pair<int,int> >q;
	d[s]=0;
	q.push({0,s});
	while(!q.empty()) {
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=Link[x];i;i=e[i].nxt) {
			int y=e[i].y,v=e[i].v;
			if(d[y]>d[x]+v) {
				d[y]=d[x]+v;
				q.push({-d[y],y});
			}
		}
	}
}
int w[N],a[N],t[N];
struct node {
	int x,y,id;
	bool friend operator < (node a,node b) {
		return a.x<b.x;
	}
}o[N];
int ans[N];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read();
	int n=read(),m=read(),D=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++) {
		int k=read();
		for(int j=1;j<=k;j++) {
			a[j]=read(),t[j]=read();
			if(j==1) continue ;
			add(a[j],a[j-1],t[j]+t[j-1]);
			add(a[j-1],a[j],t[j]+t[j-1]);
		}
	}
	for(int i=1;i<=q;i++) {
		int x=read(),y=read();
		if(x>y) swap(x,y);
		o[i].id=i;
		o[i].x=x,o[i].y=y;
	}
	sort(o+1,o+q+1);
	for(int i=1;i<=q;) {
		memset(d,0x3f,sizeof(d));
		memset(vis,0,sizeof(vis));		
		dij(o[i].x);
		ans[o[i].id]=w[o[i].x]+w[o[i].y]+d[o[i].y];
		int j=i+1;
		while(o[i].x==o[j].x) {
			ans[o[j].id]=w[o[i].x]+w[o[j].y]+d[o[j].y];
			j++;
		}
		i=j;
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
