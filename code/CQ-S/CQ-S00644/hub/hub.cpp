#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;

namespace sub1{
	int n,k,tmp[N],f[N],mxd[N],sz[N];
	bool vis[N]; 
	vector<int> g[N];
	void dfs(int u,int fa,int o)
	{
		f[u] = fa,vis[u] = o,mxd[u] = 0;
		for(auto v:g[u])
		{
			if(v==fa) continue;
			dfs(v,u,o);
			mxd[u] = max(mxd[u],mxd[v]+1);
		}
	}
	int h[N],pre[N],suf[N],son[N],cnt;
	void dfs2(int u,int fa)
	{
		cnt = 0;
		for(auto v:g[u])
		{
			if(v==fa) continue;
			son[++cnt] = v;
		}
		for(int i = 1;i<=cnt;i++)
			pre[i] = max(pre[i-1],mxd[son[i]]+1);
		suf[cnt+1] = 0;
		for(int i = cnt;i;i--)
			suf[i] = max(suf[i+1],mxd[son[i]]+1);
		for(int i = 1;i<=cnt;i++)
			h[son[i]] = max({h[u],pre[i-1],suf[i+1]})+1;
		for(auto v:g[u])
		{
			if(v==fa) continue;
			dfs2(v,u);
		}
	}
	void dfs3(int u,int fa)
	{
		for(auto v:g[u])
		{
			if(v==fa) continue;
			dfs3(v,u);
			sz[u]+=sz[v];
		}
	}
	inline bool ok(int x)
	{
//		cout<<"chk"<<x<<'\n';
//		for(int i = 1;i<=n;i++) cout<<i<<":"<<vis[i]<<' '<<sz[i]<<' '<<h[i]<<'\n';
		int res = 0;
		for(int o = 0;o<2;o++)
		{
			int now = 2e9;
			for(int i = 1;i<=n;i++)
				if(vis[i]==o&&h[i]<=x) now = min(now,max(sz[i],1));
			res+=now;
		}
		return res<=k;
	}
	inline int work(int x,int y)
	{
//		cout<<"work"<<x<<' '<<y<<'\n';
		h[x] = h[y] = 0;
		dfs(x,y,0),dfs2(x,y);
		dfs(y,x,1),dfs2(y,x);
		int l = 0,r = n,res = n;
		while(l<=r)
		{
			int mid = (l+r)/2;
			for(int i = 1;i<=n;i++) sz[i] = (mxd[i]>=mid);
			dfs3(x,y),dfs3(y,x);
			if(ok(mid)) res = mid,r = mid-1;
			else l = mid+1;
		}
//		cout<<"res"<<res<<'\n';
		return res;
	}
	inline void solve()
	{
		cin>>n>>k;
		for(int i = 1;i<=n;i++) g[i].clear();
		for(int i = 1,u,v;i<n;i++)
			cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
		dfs(1,0,0);
		for(int i = 1;i<=n;i++) tmp[i] = f[i];
		int ans = 2e9;
		for(int i = 2;i<=n;i++) ans = min(ans,work(i,tmp[i]));
		cout<<ans<<'\n';
	}
	inline void main(){int T;cin>>T;while(T--)solve();}
}
namespace sub2{
	vector<int> g[N];
	int idx,dfn[N],pre[N],f[N],st[20][N],dep[N],sz[N];
	int n,k;
	void dfs(int u,int fa)
	{
		pre[dfn[u] = ++idx] = u,sz[u] = 1,dep[u] = dep[fa]+1,f[u] = fa;
		for(auto v:g[u])
		{
			if(v==fa) continue;
			dfs(v,u);
			sz[u]+=sz[v];
		}
	}
	inline int lca(int x,int y)
	{
		if(x==y) return x;
		x = dfn[x],y = dfn[y];
		if(x>y) swap(x,y);
		x++;
		int lg = __lg(y-x+1);
		if(dep[st[lg][x]]<dep[st[lg][y-(1<<lg)+1]]) return f[st[lg][x]];
		else return f[st[lg][y-(1<<lg)+1]];
	}
	inline int dis(int x,int y)
	{
		return dep[x]+dep[y]-2*dep[lca(x,y)];
	}
	struct node{
		int x,y,d;
		inline friend node operator + (node x,node y)
		{
			if(x.d==-1) return y;
			if(y.d==-1) return x;
			node res = x;
			if(y.d>x.d) res = y;
			for(auto x:{x.x,x.y})
				for(auto y:{y.x,y.y})
				{
					int tmp = dis(x,y);
					if(tmp>res.d) res.d = tmp,res.x = x,res.y = y;
				}
			return res;
		}
	}t[N<<2];
	#define ls (k<<1)
	#define rs (k<<1|1)
	#define pushup(k) (t[k] = t[ls]+t[rs])
	void build(int k,int l,int r)
	{
		if(l==r) return t[k] = (node){pre[l],pre[l],0},void();
		int mid = (l+r)/2;
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(k);
	}
	node ask(int k,int l,int r,int x,int y)
	{
		if(l>y||r<x) return {0,0,-1};
		if(l>=x&&r<=y) return t[k];
		int mid = (l+r)/2;
		return ask(ls,l,mid,x,y)+ask(rs,mid+1,r,x,y);
	}
	int tmp[N],mxd[N];
	bool vis[N];
	void dfs1(int u,int fa,int o)
	{
		f[u] = fa,vis[u] = o,mxd[u] = 0;
		for(auto v:g[u])
		{
			if(v==fa) continue;
			dfs1(v,u,o);
			mxd[u] = max(mxd[u],mxd[v]+1);
		}
	}
	int h[N],suf[N],son[N],cnt;
	void dfs2(int u,int fa)
	{
		cnt = 0;
		for(auto v:g[u])
		{
			if(v==fa) continue;
			son[++cnt] = v;
		}
		for(int i = 1;i<=cnt;i++)
			pre[i] = max(pre[i-1],mxd[son[i]]+1);
		suf[cnt+1] = 0;
		for(int i = cnt;i;i--)
			suf[i] = max(suf[i+1],mxd[son[i]]+1);
		for(int i = 1;i<=cnt;i++)
			h[son[i]] = max({h[u],pre[i-1],suf[i+1]})+1;
		for(auto v:g[u])
		{
			if(v==fa) continue;
			dfs2(v,u);
		}
	}
	void dfs3(int u,int fa)
	{
		for(auto v:g[u])
		{
			if(v==fa) continue;
			dfs3(v,u);
			sz[u]+=sz[v];
		}
	}
	inline bool ok(int x)
	{
		int res = 0;
		for(int o = 0;o<2;o++)
		{
			int now = 2e9;
			for(int i = 1;i<=n;i++)
				if(vis[i]==o&&h[i]<=x) now = min(now,max(sz[i],1));
			res+=now;
		}
		return res<=k;
	}
	inline int work(int x,int y)
	{
		h[x] = h[y] = 0;
		dfs1(x,y,0),dfs2(x,y);
		dfs1(y,x,1),dfs2(y,x);
		int l = 0,r = n,res = n;
		while(l<=r)
		{
			int mid = (l+r)/2;
			for(int i = 1;i<=n;i++) sz[i] = (mxd[i]>=mid);
			dfs3(x,y),dfs3(y,x);
			if(ok(mid)) res = mid,r = mid-1;
			else l = mid+1;
		}
		return res;
	}
	int w[N],id[N];
	inline void solve()
	{
		cin>>n>>k;
		idx = 0;
		for(int i = 1;i<=n;i++) g[i].clear();
		for(int i = 1,u,v;i<n;i++)
			cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
		dfs(1,0);
		for(int i = 1;i<=n;i++) tmp[i] = f[i];
		for(int i = 1;i<=n;i++)
			st[0][dfn[i]] = i;
		for(int i = 1;i<20;i++)
			for(int j = 1;j+(1<<i)-1<=n;j++)
				if(dep[st[i-1][j]]<dep[st[i-1][j+(1<<i-1)]]) st[i][j] = st[i-1][j];
				else st[i][j] = st[i-1][j+(1<<i-1)];
		build(1,1,n);
		for(int i = 2;i<=n;i++)
		{
			node t1 = ask(1,1,n,dfn[i],dfn[i]+sz[i]-1),t2 = ask(1,1,n,1,dfn[i]-1)+ask(1,1,n,dfn[i]+sz[i],n);
			w[i] = abs(t1.d-t2.d),id[i] = i;
		}
		sort(id+2,id+n+1,[&](int x,int y){return w[x]<w[y];});
		int ans = 2e9;
		for(int i = 2;i<=10;i++)
		{
			int x = id[i];
			ans = min(ans,work(x,tmp[x]));
		}
		cout<<ans<<'\n';
	}
	inline void main(){int T;cin>>T;while(T--)solve();}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int cid;cin>>cid;
	if(cid<=8) sub1::main();
	else sub2::main();
	return 0;
}

