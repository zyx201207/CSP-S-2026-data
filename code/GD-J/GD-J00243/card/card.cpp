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
const int N=1e6+10,mod=1e9+7;
int a[N],lp[N],f[N],ans[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],lp[a[i]]=i;
	fill(f+1,f+n+1,1);
	for(int i=1;i<=n;i++) f[lp[a[i]]+1]+=f[i],ans[a[i]]+=f[i];
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
/*
8:58 AC T4

文操是全部没写的，加上去先。

9:00 完成比赛，到时候放 Linux 下测一测

关注 Shellchen 谢谢喵。

9:17 Linux 下测样例完成

我接下来要干啥，打 2.5h 游戏吗

有效代码长度 T1>T2>T3>T4 是什么比赛

大样例没有一个题有满数据，下午要留意一下。
*/