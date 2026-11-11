#include<bits/stdc++.h>
using namespace std;
#define psb push_back
#define f(i,l,r) for(int i=l,R##R=r;i<=R##R;++i)
#define g(i,l,r) for(int i=l,R##R=r;i>=R##R;--i)
const int N=1e6+10;
int C,T,n,k,x,y,rt,d[N],mx[N],f[N],a[N],m;
bool vs[N];
vector<int>e[N];
void dfs(int u,int fa){
	f[u]=fa,d[u]=d[fa]+1;
	if(d[u]>d[rt]) rt=u;
	for(int v:e[u]) if(v!=fa) dfs(v,u);
}
void dfs2(int u,int fa){
	mx[u]=1;
	for(int v:e[u]) if(v!=fa) dfs2(v,u),mx[u]=max(mx[u],mx[v]+1);
}
vector<int>v;
void dfs3(int u,int fa){
	mx[u]=1,v.psb(u);
	for(int v:e[u]) if(v!=fa&&!vs[v]) dfs3(v,u),mx[u]=max(mx[u],mx[v]+1);
}
int pr[N],sf[N],r[N],L[N],R[N],mn[N];
bool chk(int ds){
	int as=n,s=0;
	f(i,1,m){
		v={},dfs3(a[i],0);
		for(int j:v) s+=(j!=a[i]&&mx[j]>ds);
	}
	pr[0]=n,sf[m+1]=-1;
	f(i,1,m) L[i]=max(1,i-max(0,ds-mx[a[i]]+1)),R[i]=min(m,i+max(0,ds-mx[a[i]]+1));
	f(i,1,m) pr[i]=min(pr[i-1],R[i]);
	g(i,m,1) sf[i]=max(sf[i+1],L[i]);
	f(i,1,m) mn[i]=m;
	f(i,1,m) mn[L[i]]=min(mn[L[i]],R[i]);
	r[m]=m;
	g(i,m-1,1) r[i]=min(mn[i+1],r[i+1]);
	f(i,1,m) as=min(as,max(1,i-pr[i]+1)+max(1,sf[r[i]]-r[i]+1));
	return (as+s<=k);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k; rt=0,m=0;
		f(i,1,n) e[i]={},vs[i]=0;
		f(i,1,n-1) cin>>x>>y,e[x].psb(y),e[y].psb(x);
		dfs(1,0),dfs(rt,0);
		for(int p=rt;p;p=f[p]) a[++m]=p,vs[p]=1;
		f(i,1,d[rt]>>1) rt=f[rt];
		dfs2(rt,0),sort(mx+1,mx+n+1);
		int l=0,r=mx[n-k];
		while(l<r){
			int mid=(l+r)>>1;
			if(chk(mid)) r=mid;
			else l=mid+1;
		}
		cout<<l<<'\n';
	}
	return 0;
}
