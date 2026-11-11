#include<bits/stdc++.h>
using namespace std;
#define int long long
#define i128 __int128_t
#define u128 __uint128_t
#define i16 short
#define u16 unsigned i16
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(x) ((x)&(-(x)))
#ifdef int
#define i32 signed
#define u32 unsigned
#define inf (int)(1e18)
#define popc(x) __builtin_popcountll(x)
#define ctz(x) __builtin_ctzll(x)
#define clz(x) __builtin_clzll(x)
#else
#define ll long long
#define ull unsigned ll
#define inf (int)(1e9)
#define infl (ll)(1e18)
#define popc(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
#define clz(x) __builtin_clz(x)
#define popcl(x) __builtin_popcountll(x)
#define ctzl(x) __builtin_ctzll(x)
#define clzl(x) __builtin_clzll(x)
#endif
#define push emplace
#define pb emplace_back
#define pf emplace_front
#define ppb pop_back
#define ppf pop_front
const int N=2e6+10,mod=1e9+7;
int dis[5010][5010],pre[N],nxt[N];
int a[N];
bool ok[5010][5010];
void solve1()
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ok[i][j]=0;
	for(int i=1;i<=n;i++)
	{
		int j=i+1,cc=a[i+1]-a[i];
		if(cc>d){for(int j=i+1;j<=n;j++) dis[i][j]=inf;continue;}
		for(int dd=1;dd<=n;dd++)
		{
			while(j<=n&&cc<=d) dis[i][j]=dd,cc+=a[j+1]-a[j],j++;
			cc=a[j]-a[j-1];
			if(cc>d){for(int k=j;k<=n;k++) dis[i][j]=inf;break;}
		}
	}
	int j=n;
	for(int i=n;i>=1;i--)
	{
		while(dis[i][j]>1) j--;
		nxt[i]=j;
	}
	j=1;
	for(int i=1;i<=n;i++)
	{
		while(dis[j][i]>1) j++;
		pre[i]=j;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(nxt[i]==i) continue;
		int r=nxt[nxt[i]-1];
		if(dis[i][r]!=2) continue;
		int l=nxt[nxt[i]-2]+1;
		for(int j=l;j<=r;j++) ok[i][j]=1,ans++;
	}
	for(int len=2;len<=n;len++) for(int i=1;i+len-1<=n;i++)
	{
		int j=i+len-1;
		if(ok[i][j]) continue;
		int p=nxt[i];
		if(p!=i&&ok[p][j]&&dis[p][j]!=dis[p-1][j]){ok[i][j]=1,ans++;continue;}
		p=pre[j];
		if(p!=j&&ok[i][p]&&dis[i][p]!=dis[i][p+1]){ok[i][j]=1,ans++;continue;}
	}
	cout<<ans<<'\n';
}
void solve2()
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){cout<<0<<'\n';return;}
	int dd=a[2]-a[1];
	d/=dd;
	if(d<=1){cout<<0<<'\n';return;}
	d=2*d-1;
	cout<<max(n-d,0ll)<<'\n';
}
void solve3()
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	int j=1;
	for(int i=1;i<=n;i++)
	{
		while(j<n&&a[j+1]-a[i]<=d) j++;
		nxt[i]=j;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(nxt[i]==i) continue;
		int r=nxt[nxt[i]-1];
		if(r<=nxt[i]) continue;
		int l=nxt[nxt[i]-2]+1;
		if(l<=r) ans+=r-l+1;
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c<=10) while(t--) solve1();
	else if(c<=12) while(t--) solve2();
	else if(c<=14) while(t--) solve3();
	return 0;
}
/*
目前是平方做法+A+B，56pts

不会正解/ll
*/