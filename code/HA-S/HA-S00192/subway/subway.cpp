#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N=510,M=5e5+10;
long long dis[M];
typedef pair<long long,pair<int,int>> PII;
vector<pair<int,int>> g[M];
int w[N][M];
int T[M];
int C,n,m,d,q;
void dijkstra(int s,int t) {
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<PII,vector<PII>,greater<PII>> q;
	q.push({0,{s,0}});
	while(q.size()) {
		long long idx=q.top().first;
		int u=q.top().second.first,tr=q.top().second.second;
		q.pop();
		for(auto tt:g[u]) {
			int v=tt.first,trn=tt.second;
			if(trn==tr) {
				if(dis[u]+w[tr][v]<dis[v]) {
					dis[v]=idx+w[tr][v];
					q.push({idx,{v,tr}});
				}
			} else {
				if(dis[u]+w[trn][v]+w[tr][u]<dis[v]) {
					dis[v]=idx+w[tr][u]+w[trn][u]+w[trn][v];
					q.push({idx+w[tr][u]+w[trn][u],{v,trn}});
				}
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>T[i];
	}
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		int x,lst;
		cin>>x;
		cin>>w[i][x];
		lst=x;
		for(int j=2; j<=k; j++) {
			cin>>x;
			cin>>w[i][x];
			g[x].push_back({lst,i});
			g[lst].push_back({x,i});
		}
	}
	while(q--) {
		int s,t;
		cin>>s>>t;
		dijkstra(s,t);
		cout<<T[s]+T[t]+dis[t]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
