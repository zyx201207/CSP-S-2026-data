#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,t,n,d,dis[N],vis[N],cnt[N];
vector<int>g[N];
void dijkstra(int s){
	priority_queue<pair<int,int>>q;
	memset(dis,0x3f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:g[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=1; 
				q.push({dis[v],v});
			}
			else if(dis[v]==dis[u]+1)cnt[v]++;
		}
	}
}
void solve(){
	int ans=0;
	vector<int>x(n+1,0);
	cin>>n>>d;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)if(abs(x[i]-x[j])<=d)g[i].push_back(j);
	for(int i=1;i<=n;i++){
		dijkstra(i);
		for(int j=1;j<=n;j++)if(cnt[j]==2)ans++;
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
