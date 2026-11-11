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
	int cid,n,d,X[N],lst[N],nxt[N];
	namespace solve1{
		int L[N],R[N],fa[N],f[N];
		int sum[N];
		int anc(int u){return fa[u]<0?u:(fa[u]=anc(fa[u]));}
		int merge(int u,int v)
		{
			u=anc(u),v=anc(v);
			if(u==v) return 0;
			if(fa[u]>fa[v])
				std::swap(u,v);
			L[u]=min(L[u],L[v]);
			R[u]=max(R[u],R[v]);
			fa[u]+=fa[v];fa[v]=u;
			return 1;
		} 
		void run()
		{
			int ans=0;
			for(int l=1;l<=n;l++)
			{
				for(int i=l;i<=n;i++) fa[i]=-1,L[i]=R[i]=i;
				sum[l-1]=0;sum[l]=1;f[l]=0;
				for(int r=l+1;r<=n;r++)
				{
					int p=max(l,lst[r]);f[r]=f[p]+1;
					if(p==r) break;
					if(f[r]==f[r-1]) merge(r,r-1);
					int pr=R[anc(p)],st=min(3ll,sum[pr]-sum[p-1]);
					ans+=(st==2);sum[r]=sum[r-1]+st;
				}
			}
			print(ans);
		}
	}
	namespace solve2{
		int L[N],R[N],fa[N],f[N];
		int sum[N];
		int anc(int u){return fa[u]<0?u:(fa[u]=anc(fa[u]));}
		int merge(int u,int v)
		{
			u=anc(u),v=anc(v);
			if(u==v) return 0;
			if(fa[u]>fa[v])
				std::swap(u,v);
			L[u]=min(L[u],L[v]);
			R[u]=max(R[u],R[v]);
			fa[u]+=fa[v];fa[v]=u;
			return 1;
		}
		void run()
		{
			int ans=0;
			for(int i=1;i<=n;i++) fa[i]=-1,L[i]=R[i]=i;
			sum[1]=1;f[1]=0;
			for(int r=2;r<=n;r++)
			{
				int p=lst[r];f[r]=f[p]+1;
				if(p==r) break;
				if(f[r]==f[r-1]) merge(r,r-1);
				int pr=R[anc(p)],st=min(3ll,sum[pr]-sum[p-1]);
				ans+=(st==2)*(n-r+1);sum[r]=sum[r-1]+st;
			}
			print(ans);
		}
	}
	namespace solve3{
		int sz[N];
		void run()
		{
			for(int i=1;i<=n;i++) sz[i]=0;
			for(int i=1;i<=n;i++) sz[lst[i]]++;
			int ans=0;
			for(int l=1;l<=n;l++)
			{
				int p=nxt[l];if(p==l||p==l+1) continue;
				ans+=sz[p-1];
			}
			print(ans);
		}
	}
	void solve()
	{
		n=read(),d=read();
		for(int i=1;i<=n;i++) X[i]=read();
		for(int i=1,j=1;i<=n;i++)
		{
			while(X[i]-X[j]>d) j++;
			lst[i]=j;
		}
		for(int i=n,j=n;i>=1;i--)
		{
			while(X[j]-X[i]>d) j--;
			nxt[i]=j;
		}
		if(cid<=10) solve1::run();
		else if(11<=cid&&cid<=12) solve2::run();
		else if(13<=cid&&cid<=14) solve3::run();
		else solve1::run();
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
//	system("fc migrate.out migrate.ans");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	return LMY::Main();
}
//s->same1->u->p1->p2->p3->p4->v->same2->t
//s->same1->u->q1->q2->q3->q4->v->same2->t
//suppose that p1<q1:
//	u<p1<q1<p2<q2<p3<q3<p4<q4<v 
//

