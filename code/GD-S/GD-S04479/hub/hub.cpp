#include<bits/stdc++.h>
using namespace std;
const int N=3e5+7;
long long c,t,n,k,fa[N],ans;
bool f[N];
vector<int> g[N];
struct node{
	int u,v;
};
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
node tt[N];
bool vis[N];
long long mindis=1e18;
void dfs2(int x,long long dis,int ex){
	if(x==ex){
		mindis=min(dis,mindis);
		return;
	}
	for(int nx:g[x]){
		if(!vis[nx]) dfs2(nx,dis+1,ex);
	}
	return;
	
}
long long d(int x){
	if(f[x]) return 0;
	long long mmans=1e18;
	for(int i=1;i<=n;i++){
		if(!f[i]) continue;
		mindis=1e18;
		memset(vis,0,sizeof(vis));
		vis[x]=1;
		dfs2(x,0,i);
		mmans=min(mindis,mmans);
	}
	return mmans;
}
void dfs(int x){
	if(x>n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			fa[i]=i;
			if(f[i]){
				cnt++;
			}
		}
		if(cnt!=k) return;
		vector<int> gg[N];
		for(int i=1;i<n;i++){
			if(f[tt[i].u]&&f[tt[i].v]){
				gg[tt[i].u].push_back(tt[i].v);
				gg[tt[i].v].push_back(tt[i].u);
				merge(tt[i].v,tt[i].u);
			}
		}
		int q1=-1,q2=-1;
		for(int i=1;i<=n;i++){
			if(!f[i]) continue;
			if(fa[i]!=q1){
				if(fa[i]!=q2){
					if(q2==-1) q2=fa[i];
					else return;
				}
				else if(q1==-1) q1=fa[i];
			}
		}
		long long banjing=0;
		for(int i=1;i<=n;i++){
			banjing=max(d(i),banjing);
		}
		ans=min(ans,banjing);
		return;
	}
	f[x]=1;
	dfs(x+1);
	f[x]=0;
	dfs(x+1);
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		ans=1;
		for(int i=1;i<=n;i++) g[i].clear();
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			//g[u].push_back(v);
			//g[v].push_back(u);
			//tt[i].u=u;tt[i].v=v;
		}
		//dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
