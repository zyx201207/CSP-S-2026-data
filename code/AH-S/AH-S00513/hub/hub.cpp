#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ppc __builtin_popcountll
const int N=1000010; 
int c,T,n,k;
vector<int> e[N];

namespace Sub1{
	int d[N],vis[N],co[N];
	void dfs(int u,int dep,int pre){
		//~ cerr<<"DFS"<<u<<' '<<dep<<' '<<pre<<'\n';
		d[u]=min(d[u],dep);
		for(auto v:e[u]) if(v!=pre) dfs(v,dep+1,u);
	}
	void col(int u,int pre){
		co[u]=1;
		for(auto v:e[u]) if(v!=pre&&vis[v]) col(v,u);
	}
	void solve(){
		cerr<<"Sub 1\n";
		int ans=1e18;
		for(int S=0;S<(1<<n);S++) if(ppc(S)==k){
			for(int i=1;i<=n;i++) d[i]=1e18,vis[i]=0,co[i]=0;
			int cnt=0;
			for(int i=1;i<=n;i++) if((S>>(i-1))&1) {dfs(i,0,0);vis[i]=1;}
			for(int i=1;i<=n;i++) if(vis[i]&&!co[i]) cnt++,col(i,0);
			//~ if(cnt>2) {
				//~ for(int i=1;i<=n;i++) if((S>>(i-1))&1) cerr<<i<<" ";
				//~ cerr<<'\n';
				//~ for(int i=1;i<=n;i++) cerr<<d[i]<<' ';
				//~ cerr<<'\n';
			//~ }
			//~ if(*max_element(d+1,d+1+n)==1){
				//~ cout<<cnt<<'\n';
				//~ for(int i=1;i<=n;i++) if((S>>(i-1))&1) cout<<i<<' ';
				//~ cerr<<"D=";for(int i=1;i<=n;i++) cerr<<d[i]<<' ';cerr<<'\n';
			//~ }
			if(cnt<=2) ans=min(ans,*max_element(d+1,d+1+n));
			//~ cerr<<*max_element(d+1,d+1+n)<<'\n';
		}cout<<ans<<'\n';
	}
}
signed main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	cin>>c>>T;while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1,u,v;i<n;i++) cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
		if(n<=10){Sub1::solve();continue;}
	}
}
