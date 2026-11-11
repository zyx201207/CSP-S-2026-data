#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=5e5+609;
const int M=1e7+20009;
int c,n,m,d,q;
ll w[N];
int k;
int tot;
struct edge{
	int u,v;
	ll w;
}e[M];
int cnt=0;
int pre[N];
void add(int u,int v,ll w){
	cnt++;
	e[cnt].u=u;e[cnt].v=v;
	e[cnt].w=w;
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	if(pre[x]==x)return x;
	return pre[x]=find(pre[x]);
}
vector<pair<int,ll> > x[N];
int dep[N];
ll len[N];
int fa[N][31];
void init(int now,int dad){
	dep[now]=dep[dad]+1;
	fa[now][0]=dad;
	for(int i=0;i<x[now].size();i++){
		int to=x[now][i].fi;
		if(dad==to)continue;
		len[to]=len[now]+x[now][i].se;
		init(to,now);
	}
}
int lca(int a,int b){
	if(dep[a]!=dep[b]){
		if(dep[a]<dep[b])swap(a,b);
		for(int i=29;i>=0;i--){
			if((1ll<<i)&(dep[a]-dep[b]))a=fa[a][i];
		}
	}
	if(a==b)return a;
	for(int i=29;i>=0;i--){
		if(fa[a][i]!=fa[b][i]){
			a=fa[a][i];
			b=fa[b][i];
		}
	}
	return fa[a][0];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	tot=m;
	for(int i=1;i<=n;i++){
		cin>>k;
		tot++;
		for(int j=1;j<=k;j++){
			int a=0;
			ll t=0;
			cin>>a>>t;
			add(tot,a,t);
		}
	}
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=tot;i++)pre[i]=i;
	for(int i=1;i<=cnt;i++){
		int fx=find(e[i].u);
		int fy=find(e[i].v);
		if(fx!=fy){
			pre[fy]=fx;
			x[e[i].u].push_back({e[i].v,e[i].w});
			x[e[i].v].push_back({e[i].u,e[i].w});
		}
	}
	init(1,0);
	for(int j=1;j<=29;j++){
		for(int i=1;i<=tot;i++){
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	while(q--){
		int X=0,Y=0;
		cin>>X>>Y;
		ll val=len[X]+len[Y]-2*len[lca(X,Y)]+w[X]+w[Y];
		cout<<val<<endl;
	}
	return 0;
} 
