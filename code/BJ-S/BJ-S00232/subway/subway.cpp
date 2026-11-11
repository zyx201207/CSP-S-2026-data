#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,f;
	long long w;
};
struct node2{
	int s,e,id;
};
bool cmp(node2 a,node2 b){
	if(a.s==b.s) return a.e<b.e;
	return a.s<b.s;
}
bool operator <(node a,node b){
	return a.w>b.w;
}
int c,n,m,d,q;
int p[500005];
int t[505][500005];
int a[505][500005];
vector<node> g[500005];
long long dis[500005];
bool vis[500005];
node2 qs[100005];
int ans[100005];
priority_queue<node> pq;
void dijkstra(int s){
	pq.push({s,0,0});
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	while(!pq.empty()){
		int u=pq.top().v,f=pq.top().f;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(node it:g[u]){
			int v=it.v,to=it.f;
			if(f==to) continue;
			long long w=0;
			w=t[to][u]+t[to][v];
			if(dis[u]+w<dis[v]){
//				cout<<u<<"->"<<v<<" "<<dis[u]<<"+"<<t[to][u]<<"+"<<t[to][v]<<"<"<<dis[v]<<"\n";
				dis[v]=dis[u]+w;
				pq.push({v,to,dis[v]});
			}
		}
	}
}
void solve2(){
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][a[i][j]];
		}
		for(int l=1;l<k;l++){
			for(int r=l+1;r<=k;r++){
				g[a[i][l]].push_back({a[i][r],i,0});
				g[a[i][r]].push_back({a[i][l],i,0});
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qs[i].s>>qs[i].e;
		qs[i].id=i;
	}
	sort(qs+1,qs+1+q,cmp);
	int tmp=0;
	for(int i=1;i<=q;i++){
		int s=qs[i].s,e=qs[i].e,id=qs[i].id;
		if(s!=tmp) dijkstra(s);
		ans[id]=dis[e]+p[s]+p[e];
		tmp=s;
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	solve2();
	
	return 0;
}
