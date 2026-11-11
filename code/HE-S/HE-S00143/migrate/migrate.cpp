#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+50,INF=1e18;
int c,t,n,d,ans;
int x[N],dist1[N],dist2[N],sum[N];
vector<int> ve[N];

inline void dfs(int x){
	for(int i=1;i<=n;i++) sum[i]=0;
	int u,v,w;
	priority_queue<pair<int,int> >q;
	for(int i=1;i<=n;i++) dist1[i]=dist2[i]=INF;
	dist1[x]=0; q.push({0,x});
	while(!q.empty()){
		auto now=q.top();q.pop();
		u=now.second,w=now.first;
		if(w>dist1[u]) continue;
		for(int to:ve[u]){
			if(dist1[to]>dist1[u]+1){
				dist1[to]=dist1[u]+1;
				q.push({dist1[to],to});
			}
		}
	}
	dist2[x]=0; q.push({0,x});
	while(!q.empty()){
		auto now=q.top();q.pop();
		u=now.second,w=now.first;
		if(w>dist2[u]) continue;
		for(int to:ve[u]){
			if(dist2[to]>=dist2[u]+1){
				dist2[to]=dist2[u]+1;
				q.push({dist2[to],to});
				if(dist2[to]==dist1[to]) sum[to]++;
			}
		}
	}
	for(int i=1;i<=n;i++) if(sum[i]==2) ans++;
}

inline void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) ve[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]>d) break;
			else ve[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++) dfs(i);
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--) solve();	
	return 0;
}
