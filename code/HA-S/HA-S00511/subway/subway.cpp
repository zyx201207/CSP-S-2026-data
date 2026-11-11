#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
const int M=500;
int c,n,m,D,q,vis[N];
ll d[N];
vector<int> g[N*2+M];
vector<int> e[N*2+M];
void add(int u,int v,int w=1)
{
	g[u].push_back(v);
	e[u].push_back(w);
	return;
}
struct Node{
	int u,dis;
	bool operator < (const Node &x) const{
		return x.dis<dis;
	}
};
priority_queue<Node> pq;
void dij(int s)
{
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[s]=0;
	pq.push({s,0});
	while(!pq.empty()){
		int u=pq.top().u,w=pq.top().dis;
		pq.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i],w=e[u][i];
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				if(!vis[v]){
					pq.push({v,d[v]});
					vis[v]=1;
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>c>>m>>n>>D>>q;
	for(int i=1;i<=n;i++){
		int w;
		cin>>w;
		add(i,i+n,w),add(i+n,i,w);
	}
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,v;
			cin>>u>>v;
			add(2*n+i,u,v),add(u,2*n+i,v);
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		s+=n,t+=n;
		dij(s);
		cout<<d[t]<<'\n';
	}
	return 0;
}
