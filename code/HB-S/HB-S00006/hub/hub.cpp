#include<bits/stdc++.h>
using namespace std;
const int N=2e4+2,INF=1e9;
int n,k,fa[N],lca[N][N],le[N],ans=INF;
bool book[N],book2[N];
vector<vector<int>>tree(N);
int g_f(int x){
	if(fa[x]!=fa[fa[x]])fa[x]=g_f(fa[x]);
	return fa[x];
}
void dfs(int f,int x){
	le[x]=le[f]+1;
	fa[x]=x;
	book[x]=true;
	for(int v:tree[x]){
		if(v==f)continue;
		dfs(x,v);
	}
	for(int i=1;i<=n;i++){
		if(book[i]==true){
			lca[i][x]=g_f(i);
			lca[x][i]=lca[i][x];
		}
	}
	fa[x]=fa[f];
}
void dfs2(int step,int x){
	if(step==k){
		int maxn=0;
		for(int i=1;i<=n;i++){
			int minn=INF;
			for(int j=1;j<=n;j++){
				if(!book2[j])continue;
				int l=lca[i][j];
				minn=min(minn,2*le[l]-le[i]-le[j]);
			}
			maxn=max(maxn,minn);
		}
		ans=min(maxn,ans);
	}
	for(int i=x;i<=n;i++){
		if(!book2[i]){
			book2[i]=true;
			dfs2(step+1,i);
		}
	}
	book2[x]=false;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		
	}
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(0,1);
	for(int i=1;i<=n;i++){
		book2[i]=true;
		dfs2(1,i);
	}
	cout<<ans;
	return 0;
}
