#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,m,n,d,qq,tot,dis[10001],a[505],b[505],v[N];
int ver[N],w[N],nxt[N],head[N];
void add(int x,int y,int z){
	ver[++tot]=y,w[tot]=z;
	nxt[tot]=head[x],head[x]=tot;
}
priority_queue<pair<int,int> > q;
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(v,0,sizeof(v));
	dis[s]=0;
	q.push({0,s});
	while(q.size()){
		int t=q.top().second;
		q.pop();
		if(v[t])
			continue;
		v[t]=1;
		for(int i=head[t];i;i=nxt[i]){
			int to=ver[i];
			if(dis[to]>dis[t]+w[i]){
				dis[to]=dis[t]+w[i];
				q.push({-dis[to],to});
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int op,x,y;
		cin>>op;
		cin>>x>>y;
		b[x]++;
		int dx=b[x]*m+x;
		add(x,dx,y);
		add(dx,x,y);
		int last=dx;
		for(int j=2;j<=op;j++){
			cin>>x>>y;
			b[x]++;
			int dx=b[x]*m+x;
			add(x,dx,y);
			add(dx,x,y);
			add(last,dx,0);
			add(dx,last,0);
			last=dx;
		}
		
	}
	
	while(qq--){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]+a[x]+a[y]<<endl;
	}
	
	return 0;
}
