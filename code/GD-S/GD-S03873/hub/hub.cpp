#include<bits/stdc++.h>
using namespace std;using ll=long long;using ull=unsigned long long;

constexpr int N=19,inf=0x3f3f3f3f;
int n,k,ans=inf;
bitset<N> vis;
bitset<N> is;
basic_string<int> adj[N];
queue<pair<int,int>> q;

void dfs(int u){
	vis[u]=1;
	for(auto v:adj[u]){
		if(vis[v]) continue;
		if(!is[v]) continue;
		dfs(v);
	}
}

void solve(){
	cin>>n>>k;
	int U=(1<<n)-1;
	for(int i=1,u,v;i<=n-1;i++){
		cin>>u>>v;
		u--,v--;
		adj[u]+=v,adj[v]+=u;
	}
	if(n==k){
		cout<<0<<'\n';
		ans=inf;
		for(auto& x:adj) x.clear();
		return;
	}
	for(int S=0;S<=U;S++){
		if(__builtin_popcount(S)!=k) continue;
		for(int i=0;i<n;i++){
			if(S>>i&1) is[i]=1;
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			if(is[i]&&!vis[i]){
				cnt++;
				dfs(i);
			}
		}
		vis=0;
		if(cnt<=2){
			int res=0;
			for(int i=0;i<n;i++){
				if(is[i]) continue;
				while(q.size()) q.pop();
				q.emplace(i,0);
				while(q.size()){
					int u=q.front().first,w=q.front().second;
					q.pop();
					vis[u]=1;
					res=max(res,w);
					if(is[u]) break;
					for(auto v:adj[u]){
						if(vis[v]) continue;
						q.emplace(v,w+1);
					}
				}
			}
			ans=min(ans,res);
		}
		is=0;
		vis=0;
	}
	cout<<ans<<'\n';
	ans=inf;
	for(auto& x:adj) x.clear();
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}

/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
