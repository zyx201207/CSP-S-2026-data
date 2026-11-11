#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int w[N];
int a[505][N];
int t[505][N];
int head[N],to[N<<1],nxt[N<<1],cnt;
void add(int u,int v){
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
bool vis[N];
void dfs(int u,int e){
//	cout<<u<<" ";
	vis[u]=1;
	if(u==e)	return ;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!vis[v]){
			dfs(v,e);
		}
	} 
}
int k[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
			add(a[i][j],a[i][j+1]);
			add(a[i][j+1],a[i][j]);
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		dfs(u,v);
	}
	return 0;
}
