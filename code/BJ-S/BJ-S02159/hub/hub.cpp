#include <bits/stdc++.h>
using namespace std;
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
#define pre(i,n) for(int i = n;i;--i)
#define rep(i,n) for(int i = 1;i <= n;++i)
#define rpt(i,a,n) for(int i = a;i <= n;++i)
#define repg(i,u) for(int i = head[u];i;i = e[i].nxt)
#define WR(x) cerr<<#x<<':'<<x<<endl
#define ll long long
#define swap(x,y) (x ^= y ^= x ^= y)
constexpr int N = 1e6 + 5,inf = 1e8;
int c,T;
namespace sub1{
	constexpr int M = 105;
	int f[M][M],fa[N],siz[N],tmp[M],dis[N],n,k,u,v,no,res;
	vector <int> g[N];
	void dfs1(int u,int f){
		fa[u] = f;
		for(auto v : g[u]) if(v ^ fa[u]) dfs1(v,u);
	}
	bool is[N];
	void dfs2(int u){
		siz[u] = 1,is[u] = true;
		f[u][0] = 0,f[u][1] = 0;
		for(auto v : g[u]) if(v ^ fa[u] && v ^ no){
			dfs2(v),f[u][0] = max(f[u][0],f[v][0] + 1);
			rep(i,siz[u] + siz[v]) tmp[i] = inf;
			rep(i,siz[u]) rpt(j,0,siz[v]) tmp[i+j] = min(tmp[i+j],max(f[u][i],f[v][j] + !j));
			siz[u] += siz[v];
			rep(i,siz[u]) f[u][i] = tmp[i];
		}
	}
	void dfs3(int u,int fa,int d){
		dis[u] = min(dis[u],d);
		for(auto v : g[u]) if(v ^ fa && !is[v]) dfs3(v,u,d + 1);
	}
	inline int cal(int x,int y){
		dfs1(x,0);
		no = y;
		while(fa[no] ^ x) no = fa[no];
		rep(i,n) is[i] = 0;
		dfs2(x),dfs2(y);
		rep(i,n) dis[i] = inf;
		dfs3(x,0,0),dfs3(y,0,0);
		int mx = 0;
		rep(i,n) if(!is[i]) mx = max(mx,dis[i]);
		int mn = inf;
		rep(i,k - 1) mn = min(mn,f[x][min(i,siz[x])] + f[y][min(k-i,siz[y])]);
		return max(mn,mx);
	}
	inline void Main(){
		while(T--){
			cin>>n>>k,res = n;
			rep(i,n) g[i].clear();
			rep(i,n - 1) cin>>u>>v,g[u].emplace_back(v),g[v].emplace_back(u);
			rep(i,n) rpt(j,i + 1,n) res = min(res,cal(i,j));
			cout<<res<<'\n';
		}
	}
}
namespace sub13{
	int n,k,u,v,m;
	inline int solve(){
		if(k == n) return 0;
		if(k >= m) return 1;
		int len = m - 1;//dis.not cnt of points
		//res+(k1-1)+res+res+(k2-1)+res>=len
		//res*4>=len-k+2
		return ceil((double)(len - k + 2) / 4) + 1;
	}
	inline void Main(){
		while(T--){
			cin>>n>>k;
			rep(i,n - 1) cin>>u>>v;
			m = n >> 1;
			cout<<solve()<<'\n';
		}
	}
}
int main(){
	// fin("hub5.in"),fout("hub.out");
	fin("hub.in"),fout("hub.out");
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	if(c <= 6) sub1::Main();
	else if(c == 13 || c == 14) sub13::Main();
	cerr<<'\n'<<1.0 * clock() / CLOCKS_PER_SEC;
	return 0;
}