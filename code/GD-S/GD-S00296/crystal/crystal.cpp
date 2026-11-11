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
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ss=0,ans=1,j=1;
	for(int i=2;i<=n;i++)
	{
		ss+=(a[i]-a[i-1])*(i-j);
		while(ss>m) ss-=a[i]-a[j],j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
/*
能赢吗能赢吗能赢吗

14:47 AC T1，前面跑去口胡 T2 & 配 vscode 了

希望口胡的 T2 是对的 qwq

关注 Shellchen 谢谢喵。
*/