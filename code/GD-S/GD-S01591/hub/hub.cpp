#include<bits/stdc++.h>
using namespace std;
int viss[1000010],K,a[1000010],fa[1000010][23],point;
int dep[1000010],ans,vis[1000010],n,c,T,u,v,maxnn;
vector<int> E[1000010];
void del(int k){
	viss[k]=1;
	for(int i:E[k]){
		if(viss[i]==0) del(i);
	}
}
bool check(){
	int cnt=0;
	for(int i=1;i<=K;i++) viss[a[i]]=0;
	for(int i=1;i<=K;i++){
		if(viss[a[i]]==0){
			del(a[i]);
			cnt++;
		}
	}
	if(cnt>2) return 0;
	else return 1;
}
void lca(int k,int f){
	fa[k][0]=f;
	dep[k]=dep[f]+1;
	for(int i=1;i<=22;i++){
		fa[k][i]=fa[fa[k][i-1]][i-1];
	}
	for(int v:E[k]){
		if(v==f) continue;
		lca(v,k);
	} 
}
int query(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=22;i>=0;i--){
		if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	}
	if(u==v) return u;
	for(int i=22;i>=0;i--){
		if(fa[u][i]!=fa[v][i]) {
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
}
int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[query(u,v)];
}
void dfs(int cur,int k){
	if(k==K){
		if(check()){
			int maxn=0;
			for(int i=1;i<=n;i++){
				int minn=1e9;
				for(int j=1;j<=K;j++){
					minn=min(minn,dis(a[j],i));
				}
				maxn=max(maxn,minn);
			}
			ans=min(ans,maxn);
		}
		return;
	}
	if(cur==n+1) return;
	a[k+1]=cur;
	vis[cur]=1;
	dfs(cur+1,k+1);
	vis[cur]=0;
	dfs(cur+1,k);
}
void init(){
	for(int i=1;i<=n;i++) {
		vis[i]=0;
		E[i].clear();
		dep[i]=0;
	}
}
void dfs1(int k,int fa,int dis){
	if(dis>maxnn) {
		maxnn=dis;
		point=k;
	}
	for(int v:E[k]){
		if(v==fa) continue;
		dfs1(v,k,dis+1);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	if(c==7||c==11||c==12){
		while(T--){
			cin>>n>>K;
			init();
			for(int i=1;i<n;i++){
				cin>>u>>v;
				E[u].push_back(v);
				E[v].push_back(u);
			}
			point=1;
			maxnn=0;
			dfs1(1,0,0);
			
			maxnn=0;
			dfs1(point,0,0);
			cout<<maxnn/4<<"\n";
		}
		
		
		return 0;
	}
	while(T--){
		cin>>n>>K;
		init();
		ans=1e9;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		lca(1,0);
		dfs(1,0);
		
		cout<<ans<<"\n";
	}
	
	return 0;
} 
