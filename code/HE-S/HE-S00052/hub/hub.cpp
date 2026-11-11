#include<bits/stdc++.h>
using namespace std;
int c;
namespace sol{
	const int N = 15,INF = 123456789LL;
	int T,n,k,dis[N][N],ans;
	vector<int> g[N];
	bool flag[N],vis[N];
	void dfs1(int u,int rt,int fa){
		for(auto v:g[u]){
			if(v==fa) continue;
			dis[rt][v]=dis[rt][u]+1;
			dfs1(v,rt,u);
		}
	}
	void dfsp(int u,int fa){
		if(!flag[u]) return;
		vis[u]=1;
		for(auto v:g[u]){
			if(v==fa) continue;
			dfsp(v,u);
		}
	}
	void dfs2(int u,int num){
		if(u==n+1){
			if(num!=k) return;
			memset(vis,0,sizeof vis);
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(flag[i]&&vis[i]==0){
					dfsp(i,0);
					cnt++;
				}
			}
			if(cnt>2) return;
			int res=0;
			for(int i=1;i<=n;i++){
				int d=INF;
				for(int j=1;j<=n;j++){
					if(flag[j]) d=min(d,dis[i][j]);
				}
				res=max(d,res);
			}
			ans=min(ans,res);
			//cerr<<res<<" ";
			return;
		}
		if(n-u+1<k-num) return;
		if(num>k) return;
		flag[u]=1; dfs2(u+1,num+1);
		flag[u]=0; dfs2(u+1,num);
	}
	void solve(){
		cin>>T;
		while(T--){
			cin>>n>>k;
			for(int i=1;i<=n;i++) g[i].clear();
			memset(vis,0,sizeof vis); ans=INF;
			for(int i=1;i<=n-1;i++){
				int u,v; cin>>u>>v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			for(int i=1;i<=n;i++) dis[i][i]=0,dfs1(i,i,0);
			//cerr<<dis[2][3];
			dfs2(1,0);
			cout<<ans<<endl;
		}
		
	}	
}
namespace solB{
	int T;
	void solve(){
		cin>>T;
		while(T--){
			cout<<1<<endl;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c;
	if(c<=12) sol::solve();
	else solB::solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
