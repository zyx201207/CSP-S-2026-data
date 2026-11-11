#include<bits/stdc++.h>
#define ll long long
#define rep(i,X,Y) for(int i=(X);i<=(Y);i++)
#define per(i,X,Y) for(int i=(X);i>=(Y);i--)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

constexpr int MAXN=1e6+10;

int n,m;
vector<int> g[MAXN];

namespace sub1 {
	constexpr int N=110,INF=1e9;
	int dep[N],mxd[N],siz[N];
	int f[2][N][N],dp[N][N][N],pm[N][N][N];
//	h[2][N][N],h2[N][N];
	
	void dfsp(int u,int fa) {
		dep[u]=mxd[u]=(fa?dep[fa]+1:1);
		siz[u]=1;
		int now=1;
		rep(i,0,n) f[0][u][i]=f[1][u][i]=INF; //h[0][u][i]=h[1][u][i]=h2[u][i]=
		f[1][u][1]=0;
		int mx=0,sc=0;
		for(auto v:g[u]) if(v^fa) {
			dfsp(v,u);
			siz[u]+=siz[v];
			mxd[u]=max(mxd[u],mxd[v]);
			if(mxd[v]>mx) {
				sc=mx; mx=mxd[v];
			} else {
				sc=max(sc,mxd[v]);
			}
		}
		for(auto v:g[u]) if(v^fa) {
			now^=1;
			rep(i,1,siz[u]) f[now][u][i]=INF;
			int nw=(mxd[v]==mx?sc:mx)+2;
//			rep(j,0,siz[v]) h2[u][j]=min(h2[u][j],max(h2[v][j],nw));
			rep(i,1,siz[u]-siz[v]) rep(j,0,siz[v]) {
				f[now][u][i+j]=min(f[now][u][i+j],max(f[now^1][u][i],f[0][v][j]));
//				h[now][u][i+j]=min(h[now][u][i+j],max(f[now^1][u][i],min(h[0][v][j],h2[v][j])));
//				h[now][u][i+j]=min(h[now][u][i+j],max(h[now^1][u][i],f[0][v][j]));
			}
		}
		if(now) rep(i,1,siz[u]) f[0][u][i]=f[now][u][i]; // h[0][u][i]=h[now][u][i];
		f[0][u][0]=mxd[u]-dep[u]+1;
//		rep(i,0,siz[u]) h[0]
	}
	
	int ans;
	
	void dfs(int u,int fa,int ot) {
		int mx=0,sc=0;
		for(auto v:g[u]) if(v^fa) {
			if(mxd[v]>mx) {
				sc=mx; mx=mxd[v];
			} else {
				sc=max(sc,mxd[v]);
			}
		}
		rep(i,0,siz[u]) dp[u][0][i]=f[0][u][i];
		ans=min(ans,max(f[0][u][m],ot));
		for(auto v:g[u]) if(v^fa) {
			int nw=max(ot+1,(mxd[v]==mx?sc:mx)+2);
			dfs(v,u,nw);
			rep(i,0,mxd[v]) rep(j,1,siz[v]) dp[u][i+1][j]=min(dp[u][i+1][j],max(dp[v][i][j],nw+i));
		}
		rep(j,1,m-1) rep(i,0,mxd[u]) {
			int mn=INF,sd=INF;
			for(auto v:g[u]) if(v^fa) {
				if(dp[v][i][j]<mn) {
					sd=mn; mn=dp[v][i][j];
				} else sd=min(sd,dp[v][i][j]);
			}
			for(auto v:g[u]) if(v^fa) {
				int x=(dp[v][i][j]==mn?sd:mn);
				x=max(x,ot+1+i);
				ans=min(ans,max(pm[v][i][m-j],x));
			}
		}
		rep(i,0,mxd[u]) rep(j,0,siz[u]) pm[u][i][j]=min((i?pm[u][i-1][j]:INF),dp[u][i][j]);
	}
	
	void Main() {
		cin>>n>>m;
		rep(i,1,n) g[i].clear();
		rep(i,1,n-1) {
			int u,v; cin>>u>>v;
			g[u].push_back(v); g[v].push_back(u);
		}
		dfsp(1,0);
//		rep(i,1,n) rep(j,0,n) cout<<i<<' '<<j<<"  "<<f[0][i][j]<<'\n';
		ans=INF;
		memset(dp,0x3f,sizeof(dp));
		dfs(1,0,0);
		cout<<ans<<'\n';
	}
}

namespace sub0 {
	const int N=15;
	int flag[N];
	int fa[N],b[N],dis[N],vis[N];
	int find(int x) {
		if(x==fa[x]) return x;
		return fa[x]=find(fa[x]);
	}
	void Main() {
		cin>>n>>m;
		rep(i,1,n) g[i].clear();
		rep(i,1,n-1) {
			int u,v; cin>>u>>v;
			g[u].push_back(v); g[v].push_back(u);
		}
		int ans=n+1;
		rep(s,0,(1<<n)-1) {
			if(__builtin_popcount(s)!=m) continue;
			rep(i,1,n) {
				flag[i]=((s>>i-1)&1);
				fa[i]=i;
				b[i]=0;
				dis[i]=n+1;
				vis[i]=false;
			}
			rep(i,1,n) {
				for(auto v:g[i]) {
					if(flag[i]&&flag[v]) {
						fa[find(i)]=find(v);
					}
				}
			}
			
			queue<int> q;
			rep(i,1,n) {
				if(flag[i]) b[find(i)]=1,q.push(i),dis[i]=0;
			}
			int cnt=0;
			rep(i,1,n) cnt+=b[i];
			if(cnt>2) continue;
			while(!q.empty()) {
				int u=q.front(); q.pop();
				if(vis[u]) continue;
				vis[u]=true;
				for(auto v:g[u]) {
					if(dis[v]>dis[u]+1) {
						dis[v]=dis[u]+1;
						q.push(v);
					}
				}
			}
			int res=0;
			rep(i,1,n) {
				res=max(res,dis[i]);
			}
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T; cin>>C>>T;
	while(T--) {
//		if(C<=6) sub1::Main();
		if(C<=3) sub0::Main();
		else if(C<=6) sub1::Main();
	}
	return 0;
} 
