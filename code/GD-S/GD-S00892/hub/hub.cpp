#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e6+5;
const int lg=25;
int n,k;
vector<int> g[N];
int a[N];
int ans;
int dep[N],fa[N][lg];
void dfs(int u,int f){
	dep[u]=dep[fa[u][0]=f]+1;
	for(int i=1;i<=lg;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int v:g[u]){
		if(v!=f){
			dfs(v,u);
		}
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
	for(int i=lg;~i;i--){
		int fu=fa[u][i];
		if(dep[fu]>=dep[v]){
			u=fu;
		}
	}
	if(u==v){
		return u;
	}
	for(int i=lg;~i;i--){
		int fu=fa[u][i],fv=fa[v][i];
		if(fu!=fv){
			u=fu,v=fv;
		}
	}
	return fa[u][0];
}
int check(){
	int res=0;
	for(int i=1;i<=n;i++){
		int tmp=n;
		for(int j=1;j<=k;j++){
			tmp=min(tmp,dep[i]+dep[a[j]]-2*dep[lca(i,a[j])]);
		}
		res=max(res,tmp);
	}
	// for(int i=1;i<=k;i++){
		// cout<<a[i]<<" ";
	// }
	// cout<<"\n"<<res<<"\n";
	return res;
}
void RND(int dep){
	if(dep==k+1){
		ans=min(check(),ans);
		return;
	}
	for(int i=a[dep-1]+1;i<=n;i++){
		a[dep]=i;
		RND(dep+1);
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		ans=n;
		if(n>=10){
			int tim=1e3;
			while(tim--){
				int B=sqrt(n);
				for(int i=1;i<=k;i++){
					a[i]=rand()%(a[i-1]+B)+1;
				}
				ans=min(ans,check());
			}
		}
		else{
			RND(1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
