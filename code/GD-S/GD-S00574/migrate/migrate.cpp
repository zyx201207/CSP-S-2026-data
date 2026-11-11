#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#define psbk push_back
#define mkp make_pair
#define F first
#define S second
int c,T,n;
ll x[1000010],dis[1000010],d;
vector<int> G[1000010];
ll ans,cnt[1000010];
bool vis[1000010];
inline void BFS(int s){
	priority_queue<PII,vector<PII>,greater<PII>> pq;
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	pq.push(mkp(0,s));
	while(!pq.empty()){
		ll d=pq.top().F;
		int u=pq.top().S;
		pq.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(auto v:G[u]){
			ll dd=d+1;
			if(dd==dis[v]) cnt[v]++;
			else if(dd<dis[v]){
				dis[v]=dd;
				cnt[v]=1;
				pq.push(mkp(dd,v));
			}
		}
	}
	for(int i = 1;i<=n;i++) if(cnt[i]==2) {
		ans++;
	}
}
inline void solve(){
	for(int i = 1;i<=n;i++) G[i].clear();
	ans=0;
	cin>>n>>d;
	for(int i = 1;i<=n;i++) cin>>x[i];
	for (int i = 1;i<n;i++) 
		for(int j = i+1;j<=n;j++) 
			if(x[j]-x[i]<=d) G[i].psbk(j); 
			else break;
	
	for(int i = 1;i<=n;i++)
		BFS(i);
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
