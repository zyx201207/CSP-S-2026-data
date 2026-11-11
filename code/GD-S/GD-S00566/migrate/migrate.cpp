#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long N=1e6+10,INF=1e18;
ll c,t,n,d,x[N],dist[N],cnt[N];
vector<int> g[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]<=d) g[j].push_back(i);
				else break;
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			queue<int> q;
			for(int i=1;i<=n;i++) dist[i]=INF,cnt[i]=0;
			if(g[i].empty()) continue;
			dist[i]=0;
			cnt[i]=1;
			q.push(i);
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int v:g[u]){
					if(dist[v]>dist[u]+1){
						dist[v]=dist[u]+1;
						cnt[v]=1;
						q.push(v);
					}else if(dist[v]==dist[u]+1){
						cnt[v]+=cnt[u];
					}
				}
			}
			for(int j=i;j<=n;j++) if(cnt[j]==2) ans++;
		}
		cout<<ans<<'\n';
	}
}
