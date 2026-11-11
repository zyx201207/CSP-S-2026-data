//GZ-S00104 贵阳市第一中学 胡源宸 
#include<bits/stdc++.h>
#define ll long long
#define ls i<<1
#define rs i<<1|1
using namespace std;
const int N=1e6+10,L=22;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll T,c,n,k,a[N],fa[N][L],d[N],len[N],lg[N],ans;
vector<ll>G[N];
bool flag[N];
void dfs(ll k){
	flag[k]=1;
	for(ll to:G[k]){
		if(!flag[to]&&a[to]){
			dfs(to);
		}
	}
	return;
}
void dfs2(ll k,ll f){
	fa[k][0]=f;
	d[k]=d[f]+1;
	len[k]=len[f]+1;
	for(ll to:G[k]){
		if(to==f) continue;
		dfs2(to,k);
	}
	return;
}
ll lca(ll x,ll y){
	if(d[x]<d[y]) swap(x,y);
	while(d[x]>d[y]){
		x=fa[x][lg[d[x]-d[y]]];
	}
	if(x==y) return x;
	for(int i=L-1;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
void solve(){
	cin>>n>>k;
	ans=INF;
	len[0]=-1;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<n;i++){
		ll u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(d,0,sizeof(d));
	memset(fa,0,sizeof(fa));
	dfs2(1,0);
	lg[1]=0;
	for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
	for(int j=1;j<L;j++){
		for(int i=1;i<=n;i++){
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	ll mask=(1ll<<n);
	for(int i=0;i<mask;i++){
		for(int j=1;j<=n;j++) a[j]=0,flag[j]=0;
		if(__builtin_popcount(i)!=k) continue;
		ll cnt=0;
		for(int j=1;j<=n;j++){
			if(i&(1ll<<(j-1))) a[j]=1;
		}
		for(int j=1;j<=n;j++){
			if(a[j]&&!flag[j]){
				dfs(j); 
				cnt++;
			}
		}
		if(cnt>2) continue;
		ll res=0;
		for(int j=1;j<=n;j++){
			if(a[j]) continue;
			ll res2=INF;
			for(int w=1;w<=n;w++){
				if(a[w]){
					res2=min(res,len[j]-len[lca(j,w)]*2+len[w]);
				}
			}
			res=max(res,res2);
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("hub.in","r",stdin);
	cin.tie(nullptr);
	freopen("hub.out","w",stdout);
	T=1;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
