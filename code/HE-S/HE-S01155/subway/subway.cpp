#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int h[N],cnt,f[N],dep[N],fa[N][25],v[N][25],c,n,m,d,q,w[N];
struct st{
	int k,x,y;
}a[N<<1];
struct edge{
	int e,ne,zhi;
}ed[N<<1];
bool cmp(st c,st d){
	return c.k<d.k;
}
int find(int k){
	if(k!=f[k]) f[k]=find(f[k]);
	return f[k];
}
void add(int x,int y,int z){
	ed[++cnt].e=y;
	ed[cnt].ne=h[x];
	ed[cnt].zhi=z;
	h[x]=cnt;
}
void dfs(int k,int faa){
	fa[k][0]=faa;
	dep[k]=dep[faa]+1;
	for(int i=1;i<=20;i++){
		fa[k][i]=fa[fa[k][i-1]][i-1];
		v[k][i]=v[fa[k][i-1]][i-1]+v[k][i-1];
	//	cout<<k<<" "<<i<<" "<<fa[k][i]<<" "<<v[k][i]<<"\n"; 
	}
	for(int i=h[k];i;i=ed[i].ne){
		if(ed[i].e==faa) continue;
		v[ed[i].e][0]=ed[i].zhi;
		dfs(ed[i].e,k);
	}
}
int lca(int x,int y){
	int ans=0;
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]){
			ans+=v[x][i];
		//	cout<<x<<" "<<i<<" "<<fa[x][i]<<" "<<v[x][i]<<"\n";
			x=fa[x][i];
		}
	}
	if(x==y) return ans;
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			ans+=v[x][i]+v[y][i];
			x=fa[x][i];y=fa[y][i];
		}
	}
	return ans+v[x][0]+v[y][0];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i],f[i]=i;
	//if(c==7 || c==8){
		for(int i=1;i<=n;i++){
			int x1,x2,x3,x4;
			cin>>x1>>x1>>x2>>x3>>x4;
			a[i]={x2+x4,x1,x3};
		}
		sort(a+1,a+1+n,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].k<<"\n";
//		}
		for(int i=1;i<=n;i++){
			int zx=find(a[i].x),zy=find(a[i].y);
			if(zx!=zy){
				f[zx]=zy;
				add(a[i].x,a[i].y,a[i].k);add(a[i].y,a[i].x,a[i].k);
			}
		}
		dep[0]=-1;
		dfs(1,0);
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
		//	cout<<lca(x,y)<<" "<<w[x]<<" "<<w[y]<<"\n"; 
			cout<<lca(x,y)+w[x]+w[y]<<"\n";
		}
//	}	

	
	
	
	return 0;
}
