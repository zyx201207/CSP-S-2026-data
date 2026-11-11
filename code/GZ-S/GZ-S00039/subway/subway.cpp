//GZ-S00039 贵阳市第一中学 吴昊然
#include<bits/stdc++.h>
using namespace std;
const int N=2e4+1;
vector<pair<int,int> > g[N];
int c,n,m,as,q,a[505][N],t[505][N],f[N][31],w[N],d[N],sd[N];
void dijkstra(){
	memset(d,0x3f3f3f3f,sizeof(d));
	queue<int> q;
	q.push(1);
	d[1]=d[0]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto x:g[u]){
			int v=x.first,wl=x.second;
			if(d[v]>d[u]+wl){
				d[v]=d[u]+wl;
				q.push(v);
			}
		}
	}
}
void dfs(int u){
	sd[u]++;
	for(auto x:g[u]){
		int v=x.first;
		sd[v]=sd[u];
		dfs(v);
	}
}
int lca(int u,int v){
	int s1=sd[u],s2=sd[v];
	while(s1>s2){
		u=f[u][0];
		s1--;
	}
	while(s1<s2){
		v=f[v][0];
		s2--;
	}
	if(u==u)return u;
	for(int i=30;i>=0;i--){
		if(f[u][i]!=f[v][i]){
			u=f[u][i];
			v=f[v][i];
		}
	}
	return f[u][0];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>as>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
		}
		for(int j=2;j<=k;j++){
			g[a[i][1]].push_back({a[i][j],t[i][a[i][j]]+t[i][i]});
			f[a[i][j]][0]=a[i][1];
		}
	}
	dfs(1);
	dijkstra();
	for(int j=1;j<=30;j++){
		for(int i=1;i<=m;i++){
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		int lr=lca(l,r);
		cout<<d[l]+d[r]-2*d[lr]+w[l]+w[r]<<'\n';
	}
	return 0;
} 
