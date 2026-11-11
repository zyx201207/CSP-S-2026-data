#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,K=5e5+5;
int c,n,m,d,q;
int w[N],k[N];
int dis[N];
bool vis[K];
vector<int>onway[K];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<vector<int>>a(m+1,vector<int>(d+1,0));
	vector<vector<int>>t(m+1,vector<int>(d+1,0));
	vector<pair<int,int>>g(m+1);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			onway[a[i][j]].push_back(i);
		}
	}
	int x,y;
	priority_queue<pair<int,int>>pq;
	while(q--){
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		dis[x]=w[x];
		pq.push({x,dis[x]});
		while(!pq.empty()){
			int u=pq.top().first,d=pq.top().second;
			pq.pop();
//			cout<<u<<' '<<d<<'\n';
			vis[u]=1;
			for(int wy:onway[u]){
				int cnt=d;
				if(onway[u].size()>1)cnt+=t[wy][u];
				for(int i=1;i<=k[wy];i++){
					int v=a[wy][i];
//					cout<<u<<' '<<v<<'\n';
					if(vis[v]||v==u)continue;
					if(t[wy][i]+cnt<dis[v]){
						dis[v]=t[wy][i]+cnt;
						pq.push({v,dis[v]});
					}
				}
			}
			
		}
		cout<<dis[y]+w[y]<<'\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
	
*/
