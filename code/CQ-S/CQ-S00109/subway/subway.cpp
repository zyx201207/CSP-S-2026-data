#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],de[600005],vis[600005],dp[600005],u,t,cnt,dep[600005],f[600005][21];
struct node{
	int v,w;
};
vector<node>a[600005],e[600005]; 
void prim(){
	priority_queue<pair<int,int> >q;
	memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	q.push({0,1});
	while(q.size()){
		int u=q.top().second,dis=q.top().first;
		q.pop();
		if(!vis[u]){
			vis[u]=1;
			for(node x:a[u]){
				int v=x.v,w=x.w;
				if(dp[v]>dp[u]+w){
					e[u].push_back({v,w});
					e[v].push_back({u,w});
					dp[v]=dp[u]+w;
					q.push({-dp[v],v});
				}
			}
		}
	}
	return ;
}
void bfs(){
	queue<node>q;
	memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	q.push({0,1});
	while(q.size()){
		int u=q.front().w,dis=q.front().v;
		q.pop();
		if(!vis[u]){
			vis[u]=1;
			for(node x:a[u]){
				int v=x.v,w=x.w;
				if(dp[v]>dp[u]+w){
					e[u].push_back({v,w});
					e[v].push_back({u,w});
					dp[v]=dp[u]+w;
					q.push({dp[v],v});
				}
			}
		}
	}
	return ;
}
void dfs(int id,int fa){
	f[id][0]=fa;
	de[id]=de[fa]+1;
	for(int i=1;i<=20;i++)f[id][i]=f[f[id][i-1]][i-1];
	for(node x:e[id]){
		int v=x.v,w=x.w;
		if(v!=fa){
			dep[v]=dep[id]+w;
			dfs(v,id);
		}
	}
	return ;
}
int lca(int u,int v){
	if(de[u]<de[v])swap(u,v);
	for(int i=20;i>=0;i--){
		if(de[f[u][i]]>=de[v])u=f[u][i];
	}
	if(u==v)return u;
	for(int i=20;i>=0;i--){
		if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
	}
	return f[u][0];
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u>>t;
			a[u].push_back({i+m,t});
			a[i+m].push_back({u,t});
		}
	}
	cnt=n+m;
	if(c>=16&&c<=19)bfs();
	else prim();
	dfs(1,0);
	while(q--){
		int a,b;
		cin>>a>>b;
		int l=lca(a,b);
		cout<<w[a]+w[b]+dep[a]+dep[b]-dep[l]*2<<'\n';
	}
	return 0;
}
