#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5,INF=1e18;
int n,k;
int rt1,rt2,mid,sum,min1,min2;
int ou[N+5],ov[N+5];
int f[N+5],f2[N+5];
int dep[N+5],jp[22][N+5];
vector<int> e[N+5];
struct Node{
	int x,y;
}g1[N+5],g2[N+5];
void init(){
	for(int i=1;i<=n;++i)
		e[i].clear();
}
void add(int x,int y){
	if(x>=mid)
		sum+=y;
}
void dfs1(int u,int father){
	f[u]=f2[u]=0;
	for(int v:e[u]){
		if(v==father||v==rt1||v==rt2)
			continue;
		dfs1(v,u);
		if(f[v]+1>=f[u])
			f2[u]=f[u],f[u]=f[v]+1;
		else f2[u]=max(f2[u],f[v]+1);
	}
	add(f[u],1);
}
void dfs2(int u,int father,int op){
	if(op==1)
		min1=min(min1,sum);
	else min2=min(min2,sum);
	for(int v:e[u]){
		if(v==father||v==rt1||v==rt2)
			continue;
		int fu=f[u],fv=f[v],f2u=f2[u],f2v=f2[v];
		add(f[u],-1),add(f[v],-1);
		if(f[v]+1==f[u])
			f[u]=f2[u];
		if(f[u]+1>=f[v])
			f2[v]=f[v],f[v]=f[u]+1;
		else f2[v]=max(f2[v],f[u]+1);
		add(f[u],1),add(f[v],1);
		dfs2(v,u,op);
		add(f[u],-1),add(f[v],-1);
		f[u]=fu,f[v]=fv,f2[u]=f2u,f2[v]=f2v; 
		add(f[u],1),add(f[v],1);
	}
}
bool check(){
	sum=0,min1=INF; 
	dfs1(rt1,0);
	dfs2(rt1,0,1);
	sum=0,min2=INF;
	dfs1(rt2,0);
	dfs2(rt2,0,2);
	return min1+min2<=k;
}
int calc(){
	int L=-1,R=n;
	while(L+1<R){
		mid=L+R>>1;
		if(check())
			R=mid;
		else L=mid;
	}
	return R;
}
void dfs(int u,int father){
	dep[u]=dep[father]+1;
	jp[0][u]=father;
	for(int i=1;i<=20;++i)
		jp[i][u]=jp[i-1][jp[i-1][u]];
	for(int v:e[u]){
		if(v==father)
			continue;
		dfs(v,u);
	}
}
int get(int x,int y){
	if(dep[x]<dep[y])
		swap(x,y);
	int res=0;
	for(int i=20;i>=0;--i)
		if(dep[jp[i][x]]>=dep[y])
			res+=(1<<i),x=jp[i][x];
	if(x==y)
		return res;
	for(int i=20;i>=0;--i)
		if(jp[i][x]!=jp[i][y])
			res+=(1<<i+1),x=jp[i][x],y=jp[i][y];
	return res+2;
}
void chkmax(int x,int y,int &maxx,Node &res){
	int dis=get(x,y);
	if(dis>maxx)
		maxx=dis,res=Node{x,y};
}
Node merge(Node p,Node q){
	if(!p.x)
		return q;
	if(!q.x)
		return p;
	int maxx=0;
	Node res;
	chkmax(p.x,q.x,maxx,res);
	chkmax(p.x,q.y,maxx,res);
	chkmax(p.y,q.x,maxx,res);
	chkmax(p.y,q.y,maxx,res);
	chkmax(p.x,p.y,maxx,res);
	chkmax(q.x,q.y,maxx,res);
	return res;
}
void dfs3(int u,int father){
	g1[u]=Node{u,u},g2[u]=Node{0,0};
	for(int v:e[u]){
		if(v==father)
			continue;
		dfs3(v,u);
		g1[u]=merge(g1[u],g1[v]);
	}
}
void dfs4(int u,int father){
	Node res=merge(g2[u],Node{u,u});
	for(int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if(v==father)
			continue;
		g2[v]=merge(g2[v],res);
		res=merge(res,g1[v]);
	}
	res=g2[u];
	for(int i=e[u].size()-1;i>=0;--i){
		int v=e[u][i];
		if(v==father)
			continue;
		g2[v]=merge(g2[v],res);
		res=merge(res,g1[v]);
	}
	for(int v:e[u]){
		if(v==father)
			continue;
		dfs4(v,u);
	}
}
int c(int x){
	if(!x)
		return 0;
	return (x-1)/2+1;
}
void solve(){
	cin>>n>>k;
	init();
	for(int i=1;i<=n-1;++i){
		cin>>ou[i]>>ov[i];
		e[ou[i]].emplace_back(ov[i]);
		e[ov[i]].emplace_back(ou[i]);
	}
	if(n<=4000){
		int ans=INF;
		for(int i=1;i<=n-1;++i){
			rt1=ou[i],rt2=ov[i];
			ans=min(ans,calc()); 
		} 
		cout<<ans<<'\n';
	}
	else if(k==2){
		dfs(1,0);
		dfs3(1,0);
		dfs4(1,0);
		int ans=INF;
		for(int i=2;i<=n;++i)
			ans=min(ans,max(c(get(g1[i].x,g1[i].y)),c(get(g2[i].x,g2[i].y))));
		cout<<ans<<'\n';
	}
	else{
		int ans=INF;
		for(int u=max(1ll,n/4-5);u<=min(n,n/4+5);++u)
			for(int v:e[u]){
				rt1=u,rt2=v;
				ans=min(ans,calc());
			}
		cout<<ans<<'\n';
	} 
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
		solve();
	return 0;
}

