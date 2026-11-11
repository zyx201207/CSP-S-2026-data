#include<bits/stdc++.h>
using namespace std;
const int N=505,M=2e4+5;
int C,n,m,d,q;
long long w[N],t[N][M],dis[M];
bool vis[N];
vector<pair<int,long long>> g[M];
vector<pair<int,int>> tmp;
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		tmp.clear();
		for(int j=1,x;j<=k;j++){
			cin>>x>>t[i][j];
			for(auto p:tmp){
				int l=p.first,r=p.second;
				g[l].push_back({x,t[i][r]+t[i][j]});
				g[x].push_back({l,t[i][r]+t[i][j]});
			}
			tmp.push_back({x,j});
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<i<<' '<<m<<' ';
//		for(auto j:g[i]) cout<<j.first<<' ';
//		cout<<'\n';
//	}
	int cnt=0;
	while(q--){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=m;i++) dis[i]=1e18,vis[i]=0;
		pq.push({dis[x]=w[x]+w[y],x});
		while(pq.size()){
			int u=pq.top().second;
			pq.pop();
			if(vis[u]) continue;
			vis[u]=1;
//			cout<<g[u].size()<<' ';
			for(auto e:g[u]){
				int v=e.first;
				long long w=e.second;
//				cout<<u<<' '<<v<<'\n';
				if(dis[v]>dis[u]+w){
//					cout<<u<<"->"<<v<<'\n';
					dis[v]=dis[u]+w;
					pq.push({dis[v],v});
				}
			}
		}
		cout<<dis[y]<<'\n';
//		cnt++;
//		if(cnt>1) break;
	}
	return 0;
}

