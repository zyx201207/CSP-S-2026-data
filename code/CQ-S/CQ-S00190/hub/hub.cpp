#include<bits/stdc++.h>
namespace LMY{
	using std::min;
	using std::max;
	using std::pair;
	#define int long long
	#define pii pair<int,int>
	#define pip pair<int,pii>
	#define ppi pair<pii,int>
	#define ppp pair<pii,pii>
	#define lp first
	#define rp second
	#define edl putchar('\n')
	#define lowbit(x) ((x)&(-(x)))
	constexpr int inf=0x3f3f3f3f3f3f3f3f;
	int read()
	{
		int x=0,f=1;char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
		while('0'<=ch&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
		return f*x;
	}
	void write(int x)
	{
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	void print(int x,char ed='\n'){write(x);putchar(ed);}
	constexpr int N=2*1e6+100,P=1e9+7;
	int cid,n,k;
	std::vector<int> G[N];
	namespace solve0{
		int f[N],mxd[N];
		void dfs1(int u,int frm,int x)
		{
			f[u]=1;mxd[u]=0;
			for(int v:G[u])
			{
				if(v==frm) continue;
				dfs1(v,u,x);
				if(mxd[v]+1>x) f[u]+=f[v];
				mxd[u]=max(mxd[u],mxd[v]+1);
			}
		}
		void dfs2(int u,int frm,int x,int &mn,int fd)
		{
			if(fd>x) return ;
			mn=min(mn,f[u]);
			int mx=fd,smx=0;
			for(int v:G[u])
			{
				if(v==frm) continue;
				smx=max(smx,mxd[v]+1);
				if(mx<smx) std::swap(mx,smx);
			}
			for(int v:G[u])
			{
				if(v==frm) continue;
				if(mx==mxd[v]+1) dfs2(v,u,x,mn,smx+1);
				else dfs2(v,u,x,mn,mx+1); 
			} 
		}
		int chk(int u,int v,int x)
		{
			dfs1(v,u,x);dfs1(u,v,x);
			int mn1=inf,mn2=inf;
			dfs2(v,u,x,mn1,0);
			dfs2(u,v,x,mn2,0);
			return mn1!=inf&&mn2!=inf&&mn1+mn2<=k;
		}
		int chk(int x)
		{
			for(int i=1;i<=n;i++)
				for(int j:G[i])
					if(i<j&&chk(i,j,x)) return 1;
			return 0;
		}
		void run()
		{
			int l=0,r=n-1;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(chk(mid)) r=mid;
				else l=mid+1;
			}
			print(l);
		}
	}
	/*
	namespace solve1{
		int f[N],rf[N],mxd[N],dep[N];
		int g[N];
		std::set<pii> st1[N],st2[N];
		void dfs(int u,int frm,int x)
		{
			dep[u]=dep[frm]+1; 
			f[u]=1;mxd[u]=0;
			st1[u].clear(),st2[u].clear();
			int mx=0,smx=0;
			for(int v:G[u])
			{
				if(v==frm) continue;
				dfs(v,u,x);
				if(mxd[v]+1>x) f[u]+=f[v];
				mxd[u]=max(mxd[u],mxd[v]+1);
				smx=max(smx,mxd[v]+1);
				if(smx>mx) std::swap(mx,smx); 
			}
			for(int v:G[u])
			{
				if(v==frm) continue;
				int cmx=(mx==mxd[v]+1?smx:mx);
				while(st1[v].size()&&st1[v].rbegin()->lp-dep[u]+cmx>x)
					st2[v].erase({st1[v].rbegin()->rp,st1[v].rbegin()->lp}),
					st1[v].erase(prev(st1[v].end()));
				if(st1[v].size()>st1[u].size())
					std::swap(st1[u],st1[v]),
					std::swap(st2[u],st2[v]);
				for(pii t:st1[v]) st1[u].insert(t);
				for(pii t:st2[v]) st2[u].insert(t);
				st1[v].clear();st2[v].clear();
			}
			st1[u].insert({dep[u],f[u]});
			st2[u].insert({f[u],dep[u]});
			g[u]=st2[u].begin()->lp;
		}
		void rdfs(int u,int frm,int x,int rmxd,int &mn)
		{
//			if(frm) 
//			{
//				solve0::dfs1(frm,u,x);
//				if(solve0::f[frm]!=rf[u])
//				{
//					print(solve0::mxd[frm],' '),print(rmxd-1);
//					print(solve0::f[frm],' '),print(rf[u]);
//					exit(1);
//				}
//			}
			mn=min(mn,g[u]+rf[u]);
			if(mn<=k) return ;
			int mx=rmxd,smx=0;
			for(int v:G[u])
			{
				if(v==frm) continue;
				smx=max(smx,mxd[v]+1);
				if(smx>mx) std::swap(smx,mx);
			}
			for(int v:G[u])
			{
				if(v==frm) continue;
				rf[v]=f[u];
				if(rmxd>x) rf[v]+=rf[u];
				if(mxd[v]+1>x) rf[v]-=f[v];
				rdfs(v,u,x,(mxd[v]+1==mx?smx:mx)+1,mn);
			}
		}
		int chk(int x)
		{
			if(x==0) return n<=k;
			int mn=inf;
			dfs(1,0,x);
			rdfs(1,0,x,0,mn);
			return mn<=k;
		}
		void run()
		{
			int l=0,r=n-1;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(chk(mid)) r=mid;
				else l=mid+1;
			}
			print(l);
		}
	}
	*/
	void solve()
	{
		n=read(),k=read();
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++)
		{
			int u=read(),v=read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		solve0::run();
	}
	signed Main()
	{
		cid=read();
		for(int T=read();T--;) solve();
		return 0;
	}
}
signed main()
{
//	system("fc hub.out hub.ans");
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	return LMY::Main();
}

