#include<bits/stdc++.h>
using namespace std;
const int MAXM=1e5+5,MAXN=505; // 站点数，线路数 
int c,m,n,d,QwQ,w[MAXM],k[MAXN],a[MAXN][MAXM],t[MAXN][MAXM],dis[MAXN+MAXM];
bool flag[MAXN+MAXM];
vector<pair<int,int> > edge[MAXM+MAXN];
void add_edge(int u,int v,int w){
	edge[u].push_back({v,w});
}
void dij(int s,int e){
	memset(0,dis,sizeof(dis));memset(0,flag,sizeof(flag));
	priority_queue<pair<int,int> > q;
	while (!q.empty()){
		int du=q.top().first,u=q.top.second;
		q.pop();
		for (auto [v,w]:edge[u]){
			if (dis[u]+w<=dis[v]){
				dis[v]=dis[u]+w;
				q.push(v,dis[v]);
			}
		}
	}
}
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>QwQ;
	for (int i=1;i<=m;i++) cin>>w[MAXN];
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			// 地铁站厅节点标号 1~m,
			add_edge(a[i][j]+m,a[i][j],t[i][j]);
			add_edge(a[i][j],a[i][j]+m,t[i][j]);
		}
	}
	while (QwQ--){
		int st,ed;cin>>st>>ed;
		cout<<dij(st,ed)<<'\n';
	}
	return 0;
} 
