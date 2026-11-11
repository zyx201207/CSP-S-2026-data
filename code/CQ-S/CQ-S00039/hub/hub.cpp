#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define req(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		vector<vector<int>> g(n+1);
		rep(i,1,n-1){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans=9e18;
		rep(st,0,(1<<n)-1){
			if(__builtin_popcount(st)!=k) continue;
			vector<int> vis(n+1),in(n+1);
			auto dfs=[&](auto &&self,int u)->void{
				vis[u]=1;
				for(auto v:g[u]){
					if(!in[v]) continue;
					if(vis[v]) continue;
					self(self,v);
				}
			};
			auto dist=[&](auto &&self,int u,int pre,int dis,int dest,int &Res)->void{
				if(u==dest){
					Res=dis;
					return;
				}
				for(auto v:g[u]){
					if(v==pre) continue;
					self(self,v,u,dis+1,dest,Res);
					if(Res!=-1) return;
				}
			};
			vector<int> ls;
			rep(i,0,n-1) if((st>>i)&1) in[i+1]=1,ls.push_back(i+1);
			int comp=0;
			rep(i,1,n) if(in[i]&&!vis[i]) ++comp,dfs(dfs,i);
			if(comp>2) continue;
			int res=0;
			rep(i,1,n){
				if(in[i]) continue;
				int val=9e18;
				for(auto j:ls){
					int Res=-1; dist(dist,i,i,0,j,Res);
					val=min(val,Res);
				}
				res=max(res,val);
			}
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
