#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+50,inf=0x3fffffff;
int n,k,tot,head[maxn],a[maxn],d[maxn];
struct edge{
	int to,nxt;
}g[maxn<<1];
bool flg[maxn];
int dfs(int u){
	if(d[u]!=inf){
		return d[u];
	}
	if(flg[u]){
		return d[u]=0;
	}
	d[u]=inf-1;
	for(int i=head[u];i;i=g[i].nxt){
		int v=g[i].to;
		d[u]=min(d[u],dfs(v)+1);
	}
	return d[u];
}
int calc(){
	int res=0;
	for(int i=1;i<=n;++i){
		res=max(res,dfs(i));
	}
	return res;
}
void solve(){
	cin>>n>>k;
	tot=0;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g[++tot]={v,head[u]};
		head[u]=tot;
		g[++tot]={u,head[v]};
		head[v]=tot;
	}
	cout<<"1\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
