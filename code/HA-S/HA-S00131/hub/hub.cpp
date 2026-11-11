#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pir pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
inline int re()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
template<typename T> inline void chkmin(T &a,T b){a=min(a,b);}
template<typename T> inline void chkmax(T &a,T b){a=max(a,b);}
int C,T;
namespace case1
{
	const int N=15;
	int n,K;
	vector<int> g[N];
	bool ck[N],mk[N];
	void dfs(int x)
	{
		mk[x]=1;
		for(int y:g[x]) if(!mk[y]&&ck[y]) dfs(y);
		return;
	}
	bool check()
	{
		int cnt=0;
		for(int i=1;i<=n;i++) mk[i]=0;
		for(int i=1;i<=n;i++) if(ck[i]&&!mk[i]) cnt++,dfs(i);
		return cnt<=2;
	}
	int dis[N];
	void dfs_dis(int x,int dep,int fa)
	{
		chkmin(dis[x],dep);
		for(int y:g[x]) if(y!=fa) dfs_dis(y,dep+1,x);
		return;
	}
	int calc()
	{
		for(int i=1;i<=n;i++) dis[i]=INT_MAX;
		for(int i=1;i<=n;i++) if(ck[i]) dfs_dis(i,0,0);
		int res=0;for(int i=1;i<=n;i++) chkmax(res,dis[i]);
		return res;
	}
	void solve()
	{
		n=re();K=re();
		for(int i=1,x,y;i<n;i++)
		{
			x=re();y=re();
			g[x].pb(y);
			g[y].pb(x);
		}
		int ans=INT_MAX;
		for(int k=0;k<(1<<n);k++) if(__builtin_popcount(k)==K)
		{
			for(int i=1;i<=n;i++) ck[i]=(k>>i-1)&1;
			if(check()) chkmin(ans,calc());
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++) g[i].clear();
		return;
	}
}
namespace case2
{
	int n,K;
	bool calc(int d)
	{
		int l=d+1,r=n/2+2-d;
		if(r-l+1<=K) return 1;
		int cha=(r-l+1)-K;
		return (cha+1)/2+1<=d;
	}
	void solve()
	{
		n=re();K=re();
		for(int i=1;i<n;i++) re(),re();
		if(K==n){printf("%d\n",0);return;}
		int l=1,r=n,mid;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(calc(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
		return;
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=re();T=re();
	while(T--)
	{
		if(C<=3) case1::solve();
		else if(C==13||C==14) case2::solve();
	}
	return 0;
}
