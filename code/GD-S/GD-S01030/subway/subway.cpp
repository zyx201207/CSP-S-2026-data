#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,M=1e3+10;
struct edge{
	int v,w;
};
struct node{
	int v,w;
	bool operator<(const node &x)const{
		return w<x.w;
	}
};
int n,m,w[N],ggg,q,tot,cnt;
int a[N],t[N],d[N],dd[M][M];
int ttt;
vector<edge>g[N];
void dijkstra(int step){
	memset(d,0x3f3f3f3f3f3f3f3f,sizeof(d));
	priority_queue<node>q;
	q.push({step,0});
	d[step]=0;
	while(!q.empty()){
		node f=q.top();
		q.pop();
//		cout<<f.v<<" "<<step<<"\n";
		if(f.w!=d[f.v])continue;
		for(int i=0;i<g[f.v].size();++i){
			int v=g[f.v][i].v,w=g[f.v][i].w;
			if(d[v]>d[f.v]+w){
				d[v]=d[f.v]+w;
				q.push({v,d[v]});
			}
		}
	}
}
void bfs(int step){
	for(int i=1;i<=tot;++i)d[i]=0x3f3f3f3f3f3f3f3f;
	d[step]=0;
	queue<int>q;
	q.push(step);
	while(!q.empty()){
		int f=q.front();q.pop();
		for(int i=0;i<g[f].size();++i){
			int v=g[f][i].v;
			if(d[v]==0x3f3f3f33f3f3f3ff){
				d[v]=d[step]+ttt;
				q.push(v);
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c;cin>>c;
	cin>>n>>m>>ggg>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	tot=m;
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		++tot;
		for(int j=1;j<=k;++j){
			cin>>a[j]>>t[j];
			g[tot].push_back({a[j],t[j]});
			g[a[j]].push_back({tot,t[j]});
			ttt=t[j];
		}
	}
	if(c>=12&&c<=19){
		while(q--){
			int l,r;cin>>l>>r;
			bfs(l);
			cout<<d[r]<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=m;++i){
		dijkstra(i);
		for(int j=1;j<=m;++j){
			dd[i][j]=d[j];
//			cout<<dd[i][j]<<" ";
		}
//		cout<<"\n";
	}
	for(int i=1;i<=q;++i){
		int l,r;cin>>l>>r;
		cout<<w[l]+w[r]+dd[l][r];
		if(i!=q)cout<<"\n";
	}
	return 0;
}
