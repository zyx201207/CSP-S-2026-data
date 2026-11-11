#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=1e6;
const ll inf=1e18;

int n,m;
vector<int> G[N+10];
int V[N+10];
bool vis[N+10];
int dep[N+10],f[N+10][30];

inline void dfs(int u,int fa=0){
	vis[u]=0;
	for(auto v:G[u]){
		if(!vis[v]) continue;
		dfs(v,u);
	}
}

inline void dfs1(int u,int fa=0){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(auto v:G[u]){
		if(v==fa) continue;
		dfs1(v,u);
	}
}

inline ll LCA(int x,int y){
	
	if(dep[x]>dep[y]) swap(x,y);
	
	for(int i=28;i>=0;i--){
		if(dep[f[y][i]]>=dep[x]){
			y=f[y][i];
		}
	}
	
	if(x==y) return x;
	
	for(int i=28;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	
	return f[x][0];
}

inline void solve(){
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		G[i].clear();
	}
	
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs1(1);
	
	for(int j=1;j<=28;j++){
		for(int i=1;i<=n;i++){
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	
	if(n<=10){
		
		ll ans=inf;
		
		for(int S=0;S<(1<<n);S++){
			
			int cnt=0,tot=0;
			for(int j=1;j<=n;j++){
				if(S&(1<<j-1)){
					V[++cnt]=j;
					vis[j]=1;
				}
			}
			if(cnt!=m) continue;
			
			for(int i=1;i<=cnt;i++){
				if(vis[V[i]]){
					dfs(V[i]);
					tot++;
				}
			}
			
			if(tot>2) continue;
			
			ll sum=0;
			for(int i=1;i<=n;i++){
				ll mi=inf;
				for(int j=1;j<=cnt;j++){
					mi=min(mi,0ll+dep[i]+dep[V[j]]-2*dep[LCA(i,V[j])]);
				}
				sum=max(sum,mi);
			}
			//if(sum==1)cerr<<V[1]<<" "<<V[2]<<" "<<V[3]<<" "<<sum<<endl;
			ans=min(ans,sum);
		}
		
		cout<<ans<<'\n';
	}
	else {
		cout<<(n+1)/2<<'\n';
	}
	//cerr<<endl;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int _;
	cin>>_>>_;
	while(_--){
		solve();
	}
	
	return 0;
}
