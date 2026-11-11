#include<bits/stdc++.h> 
//#define int long long
#define mem(a) memset(a,0,sizeof(a))
#define size(s) ((int)(s.size()))

using namespace std;

bool ppp;

const int N=1e6+5;

int c,n,k,ff[N];
vector<int> e[N];
int vis[N],dep[N],ma[N],ans;

void clean(){
	for(int i=0;i<=n+2;i++) vis[i]=dep[i]=ma[i]=ff[i]=0,e[i].clear();
	n=k=ans=0;
}

int dfs1(int o,int fa){
	ff[o]=fa;
	dep[o]=dep[fa]+1;
	int ma=o;
	for(auto u:e[o]) if(u!=fa&&!vis[u]){
		int x=dfs1(u,o);
		if(dep[x]>dep[ma]) ma=x;
	}
	return ma;
}

int dfs2(int o,int fa,int x){
	int res=0;
	dep[o]=ma[o]=dep[fa]+1;
	for(auto u:e[o]) if(u!=fa&&!vis[u]){
		res+=dfs2(u,o,x);
		ma[o]=max(ma[o],ma[u]);
	}
	return res+(ma[o]-dep[o]>=x);
}

int get(int rt,int x){
	rt=dfs1(rt,0);
	int p=rt,q=dfs1(p,0);
	int d=q;
	while(2*dep[d]>dep[p]+dep[q]) d=ff[d];
	return max(1,dfs2(d,0,x));
}

bool pd(int x){
	if(get(1,x)<=k) return 1;
//	cerr<<c<<"\n";
	if(13<=c&&c<=14){
		if(x==0) return n==k;
		int m=n/2;
		for(int i=1;i<=m;i++){
			int pp=max(1,i-(x-1)-(x-1));
			int qq=max(1,(m+1-i)-(x-1)-(x-1)-1);
			if(pp+qq<=k) return 1;
		}
		return 0;
	}
	if(1<=c&&c<=10&&n<=4000){
		for(int u=1;u<=n;u++) for(auto v:e[u]) if(u<v){
			vis[u]=1;
			int p=get(v,x);
			vis[u]=0;
			
			vis[v]=1;
			p+=get(u,x);
			vis[v]=0;
			if(p<=k) return 1;
		}
		return 0;
	}
}




struct gg{
	int u,v,l;
}a[N],b[N],ll[N],rr[N];

int f[N][25];

int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;i--) if(dep[f[u][i]]>=dep[v]) u=f[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;i--) if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
	return f[u][0];
}

gg ask(int x,int y){
	if(!x||!y) return {0,0,-1};
	return {x,y,dep[x]+dep[y]-2*dep[lca(x,y)]};
}

gg merge(gg x,gg y){
	gg a=ask(x.u,y.u);
	gg b=ask(x.u,y.v);
	gg c=ask(x.v,y.u);
	gg d=ask(x.v,y.v);
	x=ask(x.u,x.v),y=ask(y.u,y.v);
	if(a.l<x.l) a=x;
	if(a.l<y.l) a=y;
	if(a.l<b.l) a=b;
	if(a.l<c.l) a=c;
	if(a.l<d.l) a=d;
	return a;
}

void ddfs1(int o,int fa){
	dep[o]=dep[fa]+1;
	f[o][0]=fa;
	for(int i=1;i<=20;i++) f[o][i]=f[f[o][i-1]][i-1];
	a[o]={o,o,0};
	for(auto u:e[o]) if(u!=fa) ddfs1(u,o),a[o]=merge(a[o],a[u]);
}

void ddfs2(int o,int fa){
	if(o!=1) ans=min(ans,(max(b[o].l,a[o].l)+1)/2);
//	cout<<o<<"    "<<a[o].u<<" "<<a[o].v<<" "<<a[o].l<<"  "<<b[o].u<<" "<<b[o].v<<" "<<b[o].l<<"\n";
	
	ll[0]=merge(b[o],{o,o,0});
//	cout<<ll[0].u<<" "<<ll[0].v<<" "<<ll[0].l<<"\n";
	int la=0;
	for(auto u:e[o]) if(u!=fa) ll[u]=merge(ll[la],a[la]),la=u;
	
	la=0;
	reverse(e[o].begin(),e[o].end());
	for(auto u:e[o]) if(u!=fa) rr[u]=merge(rr[la],a[la]),la=u;
	
	for(auto u:e[o]) if(u!=fa) b[u]=merge(ll[u],rr[u]);
	
	for(auto u:e[o]) if(u!=fa) ddfs2(u,o);
}

void solve1(){
	ans=1e9;
	ddfs1(1,0);
	b[1]={0,0,-1};
	ddfs2(1,0);
	cout<<ans<<"\n";
}



void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(k==2){
		solve1();
		return;
	}
	int lp=0,rp=n,res,mid;
	while(lp<=rp){
		mid=lp+rp>>1;
		if(pd(mid)) res=mid,rp=mid-1;
		else lp=mid+1;
	}
	cout<<res<<"\n";
}

bool qqq;

signed main(){
//	cerr<<((&ppp)-(&qqq))/1048576.0<<"\n";
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>c>>t;
	while(t--) solve(),clean();
}
