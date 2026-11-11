#include<bits/stdc++.h>
using namespace std;
struct node{
	int v;
	long long w;
};
struct node2{
	int u;
	long long w;
	friend bool operator < (node2 a,node2 b){
		return a.w<b.w; 
	}
};
int c,n,m,d,q,w[500001],k[1001],tp[501][500001];
long long g[1001][1001];
vector<int>p[500001];
vector<node>ph[1001];
long long dijkstra(int s,int t){
	if(s==t) return 0;
	long long ans=1e18;
	for(int i=0;i<p[s].size();i++){
		for(int j=0;j<p[t].size();j++){//枚举起点与终点的经过线路数 
			priority_queue<node2>q;
			long long dis[1001];
			int si=p[s][i],ti=p[t][j];
			for(int i=1;i<=n;i++) dis[i]=1e18;
			dis[si]=0;
			q.push({si,0});
			while(!q.empty()){
				auto h=q.top();
				q.pop();
				int u=h.u;
				if(u==ti) continue; 
				for(auto op:ph[u]){
					int v=op.v,w=op.w;
					if(dis[v]>dis[u]+w){
						dis[v]=dis[u]+w;
						q.push({v,dis[v]});
					}
				}
			}
			//cout<<dis[ti]<<"\n";
			ans=min(ans,dis[ti]+tp[si][s]+tp[ti][t]);
		}
	}
	return ans+w[s]+w[t];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	memset(g,0x7f,sizeof(g));
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,v;
			cin>>u>>v;
			p[u].push_back(i); 
			tp[i][u]=v;
		}
	}
	for(int i=1;i<=m;i++){//相交的地铁线路建边 
		for(int j=0;j<p[i].size();j++){//p[i].size()<=20，时间复杂度O(md^2)≈2e7*0.5倍常数 
			for(int k=0;k<j;k++){ 
				g[p[i][j]][p[i][k]]=g[p[i][k]][p[i][j]]=min(g[p[i][j]][p[i][k]],(long long)tp[p[i][j]][i]+tp[p[i][k]][i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(g[i][j]!=0x7f7f7f7f7f7f7f7f){
				ph[i].push_back({j,g[i][j]});
				ph[j].push_back({i,g[j][i]}); 
			} 
		} 
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<dijkstra(s,t)<<"\n";
	}
	
	return 0;
}
/*
CCF评测机不要再卡我了，卡常都卡了1h了…… 
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
