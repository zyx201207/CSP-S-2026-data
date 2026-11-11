#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005;
int c,t,x[N],dis[N][N],cnt[N][N],n,d;
struct edge{
	int v,w;
};
vector<edge> g[N];
void dijkstra(int s){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,s});
	dis[s][s]=0;
	cnt[s][s]=1;
	while(!pq.empty()){
		pair<int,int> t=pq.top();
		pq.pop();
		int u=t.second;
		int w=t.first;
		if(dis[s][u]!=w)continue;
		for(edge e:g[u]){
			int newdis=w+e.w;
			if(newdis<dis[s][e.v]){
				dis[s][e.v]=newdis;
				cnt[s][e.v]+=cnt[s][u];
				pq.push({newdis,e.v});
			}
			else if(newdis==dis[s][e.v]){
				cnt[s][e.v]++;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=1e9;
				cnt[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				g[i].push_back({j,abs(x[i]-x[j])});
				g[j].push_back({i,abs(x[i]-x[j])});
			}
		}
		for(int i=1;i<=n;i++){
			dijkstra(i);
			for(int j=1;j<=n;j++){
				if(cnt[i][j]==2)ans++;
			}
		}
		cout<<ans/2<<'\n';
	}
	return 0;
}
