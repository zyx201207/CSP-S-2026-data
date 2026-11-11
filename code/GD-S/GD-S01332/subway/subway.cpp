#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+10,M=5e5;
struct aa{ll u,v,w;};
struct node{ll to,wd;};
ll c,n,m,d,q,w[N],f[N],lg[N],fa[N][21],siz[N],dep[N];
vector<ll>dian;
vector<aa> a;
vector<node> e[N];
unordered_map<ll,ll> ma;
bool cmp(aa x,aa y){return x.w<y.w;}
ll find(ll x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
void dfs(ll x,ll Fa){
	dep[x]=dep[Fa]+1;
	fa[x][0]=Fa;
	for(ll i=1;i<=lg[dep[x]];i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(node t:e[x])
		if(t.to!=Fa){
			siz[t.to]=siz[x]+t.wd;
			dfs(t.to,x);
		}
}
ll lca(ll x,ll y){
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]){x=fa[x][lg[dep[x]-dep[y]]];}
	if(x==y) return x;
	for(int i=lg[dep[x]];i>=0;i--)
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	return fa[x][0];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k,last=0;
		cin>>k;
		while(k--){
			ll x,y;
			cin>>x>>y;
			ll dx=x+(M*(i-1));
			ma[dx]++;ma[x+d*M]++;
			if(ma[dx]==1) dian.push_back(dx);
			if(ma[x+d*M]==1) dian.push_back(x+d*M);
			if(last) a.push_back({last,dx,0});
			a.push_back({dx,x+d*M,y});
			last=dx;
		}
	}
	sort(dian.begin(),dian.end());
	for(ll i=0;i<dian.size();i++){
		ma[dian[i]]=i+1;
		f[i+1]=i+1;
		lg[i+2]=lg[(i+2)/2]+1;
	}
	sort(a.begin(),a.end(),cmp);
	for(ll i=0;i<a.size();i++){
		ll mx=ma[a[i].u],my=ma[a[i].v];
		ll fx=find(mx),fy=find(my),dw=a[i].w;
		if(f[fx]!=f[fy]){
			f[fx]=fy;
			e[mx].push_back({my,dw});
			e[my].push_back({mx,dw});
		}
	}
	dfs(1,0);
	for(ll i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		ll fx=ma[x+M*d],fy=ma[y+M*d];
		ll k=lca(fx,fy);
		cout<<siz[fx]+siz[fy]-2*siz[k]+w[x]+w[y]<<"\n";
	}
	return 0;
}
