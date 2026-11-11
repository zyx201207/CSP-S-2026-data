#include<bits/stdc++.h>
using namespace std;
#define pil pair<int,long long>
#define pii pair<int,int>
#define ll first
#define rr second
#define LL long long
const int N=5e5+505;
const int M=1e6+5;
LL a[N];
struct node{
	int u,v;LL w;
	bool operator <(const node x)const{
		return w<x.w;
	}
}e[M];
vector<pil >edge[N];
int f[N];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool uni(int x,int y){
	int fx=find(x),fy=find(y);
	f[fx]=fy;
	return fx!=fy;
}
int tt,tot;
void Kru(){
	int cnt=0;
	for(int i=1;i<=tt;i++){
		if(uni(e[i].u,e[i].v)){
			cnt++;
			edge[e[i].u].push_back({e[i].v,e[i].w});
			edge[e[i].v].push_back({e[i].u,e[i].w});
		}
		if(cnt==tot-1)break;
	}
	return;
}
int F[25][N],d[N];
LL val[N];
void dfs(int x,int fa){
	F[0][x]=fa;
	for(auto t:edge[x]){
		if(t.ll==fa)continue;
		d[t.ll]=d[x]+1;
		val[t.ll]=val[x]+t.rr;
		dfs(t.ll,x);
	}
	return;
}
int lca(int x,int y){
	if(x==y)return x;
	if(d[x]>d[y])swap(x,y);
	int len=d[y]-d[x];
	for(int i=20;i>=0;i--)
		if(len&(1<<i))y=F[i][y];
	if(x==y)return x;
	for(int i=20;i>=0;i--){
		if(F[i][x]!=F[i][y]){
			x=F[i][x];
			y=F[i][y];
		}
	}
	return F[0][x];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>a[++tot];
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		int len;cin>>len;
		int id,val;
		tot++;f[tot]=tot;
		while(len--){
			cin>>id>>val;
			e[++tt].v=id;
			e[tt].u=tot;
			e[tt].w=val;
		}
	}
	sort(e+1,e+tt+1);
	Kru();
	dfs(1,0);
	for(int i=1;i<=20;i++)
		for(int j=1;j<=tot;j++)F[i][j]=F[i-1][F[i-1][j]];
	while(q--){
		int u,v;
		cin>>u>>v;
		int fa=lca(u,v);
		cout<<val[u]+val[v]-2*val[fa]+a[u]+a[v]<<"\n";
	}
}
