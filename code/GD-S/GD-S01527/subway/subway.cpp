#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
vector<pair<int,int> >has[M];
int c,n,m,d,q,w[M];
struct DATA {
	int w;
	long long len;
	bool operator<(const DATA d)const {
		return len>d.len;
	}
};
struct graph {
	vector<pair<int,int> >adj[N];
	long long d[N][N],minn[M];
	bool vis[N];
	inline void add_edge(int u,int v,int w) {
		adj[u].push_back({v,w});
	}
	inline void dijkstra(int s) {
		priority_queue<DATA,vector<DATA> >q;
		q.push(DATA{s,0});
		for(int i=1;i<=n;i++)d[s][i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
		for(int i=1;i<=m;i++)minn[i]=0x3f3f3f3f3f3f3f3f;
		d[s][s]=0;
		while(!q.empty()) {
			DATA u=q.top();
			q.pop();
			if(vis[u.w]==1)continue;
			vis[u.w]=1;
			unordered_set<int>in;
			for(auto i:adj[u.w]) {
				if(minn[i.first-n]<=d[s][u.w]+i.second)continue;
				minn[i.first-n]=d[s][u.w]+i.second;
				for(auto v:has[i.first-n]) {
					if(d[s][v.first]>d[s][u.w]+v.second+i.second) {
						d[s][v.first]=d[s][u.w]+v.second+i.second;
						in.insert(v.first);
					}
				}
			}
			for(auto v:in)q.push(DATA{v,d[s][v]});
		}
		return;
	}
}G;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++) {
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) {
			int a,t;
			cin>>a>>t;
			G.add_edge(i,a+n,t);
			has[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)G.dijkstra(i);
	for(int i=1;i<=q;i++) {
		long long ans=0x3f3f3f3f3f3f3f3f;
		int x,y;
		cin>>x>>y;
		for(auto u:has[x])
		for(auto v:has[y])
		ans=min(u.second+v.second+w[x]+w[y]+G.d[u.first][v.first],ans);
		cout<<ans<<'\n';
	}
	return 0;
}
