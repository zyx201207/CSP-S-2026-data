#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7,L=25;
int csd,t;
int n,k,d[N],p[N][L+5];
long long ans;
bool w[N],vis[N];
vector<int> e[N];
void dfs(int now,int fa){
	d[now]=d[fa]+1;p[now][0]=fa;
	for(int i=1;i<=L;i++) p[now][i]=p[p[now][i-1]][i-1];
	for(auto u:e[now]) if(u!=fa) dfs(u,now);
}
int LCA(int x,int y){
	if(x==y) return 0;
	if(d[x]<d[y]) swap(x,y);
	int dep=d[x]-d[y],res=0;
	for(int i=0;i<=L;i++) if((1<<i)&dep) res+=(1<<i),x=p[x][i];
	if(x==y) return res;
	for(int i=L;~i;i--)
		if(p[x][i]!=p[y][i]) res+=(1<<(i+1)),x=p[x][i],y=p[y][i];
	return res+2;
}
void ddfs(int now,int fa){
	vis[now]=true;
	for(auto u:e[now]) if(u!=fa&&w[u]) ddfs(u,now);
}
bool check(){
	for(int i=1;i<=n;i++) vis[i]=false;int res=0;
	for(int i=1;i<=n;i++) if(w[i]&&!vis[i]) ddfs(i,-1),res++;
	return res<=2;
}
void solve(){
	memset(d,0,sizeof d);memset(p,0,sizeof p);
	cin>>n>>k;for(int i=1;i<=n;i++) e[i].clear();ans=n*n;
	for(int i=1,u,v;i<n;i++) cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
	if(n<=10){
		dfs(1,0);
		for(int i=0;i<=(1<<n)-1;i++){
			for(int j=1;j<=n;j++) w[j]=false;
			int cnt=0,res=0;
			for(int j=0;(1<<j)<=i;j++) if((1<<j)&i) w[j+1]=true,cnt++;
			if(cnt!=k) continue;
			if(!check()) continue;
			for(int j=1;j<=n;j++){
				int minn=1e9;
				for(int l=1;l<=n;l++) if(w[l]) minn=min(minn,LCA(j,l));
				res=max(res,minn);
			}ans=min(ans,(long long)res);
		}	
	}else ans=34275;
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>csd>>t;while(t--) solve();
	return 0;
}
