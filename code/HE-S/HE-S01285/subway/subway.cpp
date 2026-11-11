#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x7f7f7f7f7f7f7f7f

const int M=2e4+5,N=505;
int c,n,m,q,d;
int t[N][M],a[N][M],w[M];
int k[N];
int to[M<<1],nxt[M<<1],h[M],val[M<<1],tot;
bool vis[M<<1];

inline void add(int u,int v,int vall)
{
	to[++tot]=v;
	nxt[tot]=h[u];
	val[tot]=vall;
	h[u]=tot;
}
int minn=inf;
inline void dfs(int u,int pos,int num)
{
	if(u==pos) return minn=min(minn,num),void();
	for(int i=h[u];i;i=nxt[i])
	{
		int v=to[i],vall=val[i];
		if(c>3&&vis[v]) continue;
		vis[v]=1;
		dfs(v,pos,num+vall);
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin >>w[i];
	for(int i=1;i<=n;++i)
	{
		cin >>k[i];
		for(int j=1;j<=k[i];++j) {cin >>a[i][j]>>t[i][j];}
		for(int j=1;j<=k[i];++j) {for(int s=j+1;s<=k[i];++s){add(a[i][j],a[i][s],t[i][j]+t[i][s]);if(c>=7){add(a[i][s],a[i][j],t[i][j]+t[i][s]);}}}
	}
	while(q--)
	{
		int x,y;
		cin >>x>>y;
		dfs(x,y,0);
		if(minn>=inf) cout <<w[x]+w[y]<<'\n';
		else cout <<w[x]+w[y]+minn<<'\n';
		for(int i=1;i<=m;++i) vis[i]=0;
		minn=inf;
	}
	return 0;
}



