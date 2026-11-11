#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll ans;
const int N=5e5+10;
int dfn[N],a[N],dn,w[N],st[20][N];
int t[505][N];
int c,d,q;
int n,m;
vector<int>g[N];
int get(int x,int y){return dfn[x]<dfn[y]?x:y;}
void dfs(int id,int f){
	st[0][dfn[id]=++dn]=f;
	for(int v:g[id])if(v!=f)dfs(v,id);
}
int lca(int u,int v){
	if(u==v)return u;
	if((u=dfn[u])>(v=dfn[v]))swap(u,v);
	int d=__lg(v-u++);
	return get(st[d][u],st[d][v-(1<<d)+1]);
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=__lg(n);i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[i][j]=get(st[i-1][j],st[i-1][j+(1<<i-1)]);
		}
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;int pos=1;
		for(int j=1,u;j<=k;j++){
			cin>>u>>t[i][pos];
			g[pos].push_back(u);g[u].push_back(pos);
			pos++; 
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		int c=lca(l,r);
		cout<<w[l]+w[r]+t[l][c]+t[c][r]+t[c][c]+t[l][l]+t[r][r]<<"\n";
	}
	return 0;
}
