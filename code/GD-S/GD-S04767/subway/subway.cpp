#include<bits/stdc++.h>//目前看下来这个更对 
using namespace std;
int c,n,m,d,q;
int w[1000009];
struct edge {
	int v,w;

};
struct node {
	int u,w;
	bool operator <(const node &tmp)const {
		return w>tmp.w;
	}
};
vector<edge>G[1000009];
int dist[1000009],totk;
void dij(int s) {
	priority_queue<node>q;
	q.push({s,0});
	dist[s]=0;
	while(!q.empty()) {
		int u=q.top().u;
		int ww=q.top().w;
		q.pop();
		for(int i=0; i<G[u].size(); i++) {
			int v=G[u][i].v;
			if(ww+G[u][i].w<dist[v]) {
				dist[v]=ww+G[u][i].w;
				q.push({v,dist[v]});
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			totk++;
			int aij,tij;
			cin>>aij>>tij;
			G[m+i].push_back({n+m+totk,0});
			G[n+m+totk].push_back({m+i,0});
			G[n+m+totk].push_back({aij,tij});
			G[aij].push_back({n+m+totk,tij});
		}
	}
	//建图
	//1~m为站厅
	//m+1~m+n为线路
	//m+n+1~m+n+sumk为站台
	int ans=0;
	for(int i=1; i<=q; i++) {
		int s,t;
		cin>>s>>t;
		for(int j=1;j<=n+m+totk;j++){
			dist[j]=1000000009;
		}
		dij(s);
		cout<<dist[t]+w[s]+w[t]<<'\n';
	}
	return 0;
}
