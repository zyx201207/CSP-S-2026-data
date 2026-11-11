#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(j);i<=(k);++i)
#define dwn(i,j,k) for(int i=(j);i>=(k);--i)
using namespace std;
const int N=5e5+7;
struct edge{
	int v,nxt;
}e[N<<1];
int a[N],n,m,head[N],cnt,nxt[N],ff[N],vis[N],siz[N],ans[N];
void add(int u,int v){
	e[++cnt]={v,head[u]};
	head[u]=cnt;
}void dfs(int u){
	++vis[a[u]];siz[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		dfs(v);siz[u]+=siz[v];
	}--vis[a[u]];
	if(!vis[a[u]])ans[a[u]]+=siz[u];
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	dwn(i,n,1){
		if(ff[a[i]]==0)nxt[i]=i+1;
		else nxt[i]=ff[a[i]];
		ff[a[i]]=i;
	}rep(i,1,n)add(nxt[i],i);
	dfs(n+1);
	rep(i,1,m-1)cout<<ans[i]<<' ';
	cout<<ans[m];
	return 0;
}
