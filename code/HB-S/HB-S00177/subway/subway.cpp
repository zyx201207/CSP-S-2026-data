#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+500+5;
const ll inf=1ll*1e18;
ll dis[maxn];
int w[maxn],c,n,m,d,q;
vector<pair<int,int> >tree[maxn];
vector<ll> mp[505];
queue<int>pq;
void bfs(int cnt){
	for(int i=1;i<=n+m;i++)dis[i]=inf;
	dis[cnt]=0;
	pq.push(cnt);
	while(!pq.empty()){
		int u=pq.front();
		pq.pop();
		for(int i=0;i<(int)tree[u].size();i++){
			int v=tree[u][i].first,di=tree[u][i].second;
			if(dis[v]>dis[u]+di){
				dis[v]=dis[u]+di;
				pq.push(v);
			}
		}
	}
	for(int i=1+n;i<=n+m;i++)mp[cnt].push_back(dis[i]);
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int ai,ki;
			cin>>ai>>ki;
			tree[i].push_back({ai+n,ki});
			tree[ai+n].push_back({i,ki});
		}
	}
	if(c<=25)for(int i=1;i<=n;i++)bfs(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		if(c<=25){
			ll ans=inf;
			for(int i=1;i<=n;i++)ans=min(ans,mp[i][x-1]+mp[i][y-1]);
			cout<<ans+w[x]+w[y]<<'\n';
		}
	}
	return 0;
}
