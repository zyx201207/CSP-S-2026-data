#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
const int N=5e3+5;
int n;ll d;
ll a[N];
int cnt[N][N];
bool vis[N][N];
int dis[N][N];
vector<int> g[N]; 
void dijkstra(int s){
	for(int i=1;i<=n;i++){
		cnt[s][i]=vis[s][i]=0;
		dis[s][i]=N;
	}
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({dis[s][s]=0,s});
	cnt[s][s]=1;
	while(!pq.empty()){
		pii nw=pq.top();
		pq.pop();
		int u=nw.se;
		if(vis[s][u]){
			continue;
		}
		vis[s][u]=1;
		for(int v:g[u]){
			if(dis[s][v]>dis[s][u]+1){
				cnt[s][v]=cnt[s][u];
				pq.push({dis[s][v]=dis[s][u]+1,v});
			}
			else if(dis[s][v]==dis[s][u]+1){
				cnt[s][v]+=cnt[s][u];
			}
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					g[i].push_back(j);
					g[j].push_back(i);
//					cout<<i<<" "<<j<<"\n";
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			dijkstra(i);
			for(int j=i+1;j<=n;j++){
//				cout<<i<<" "<<j<<" "<<cnt[i][j]<<" "<<dis[i][j]<<"\n";
				ans+=(cnt[i][j]==2);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
