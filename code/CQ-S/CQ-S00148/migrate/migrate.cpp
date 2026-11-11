#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
const int INF=0x3f3f3f3f3f3f3f;
int c,t,n,d,x[N],dis[N],p[N];
vector<int>g[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	int ans=0;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(x[i]-x[j])<=d){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[j]=INF;p[j]=0;
		}
		dis[i]=0;p[i]=1;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
		pq.push({0,i});
		while(!pq.empty()){
			int u=pq.top().second,d=pq.top().first;
			pq.pop();
			if(d>dis[u]) continue;
			for(int v:g[u]){
				if(dis[u]+1<dis[v]){
					dis[v]=dis[u]+1;p[v]=p[u];
					pq.push({dis[v],v});
				}else if(dis[u]+1==dis[v]){
					p[v]+=p[u];
				}
			}
		}
		for(int j=i+1;j<=n;j++){
			if(p[j]==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
