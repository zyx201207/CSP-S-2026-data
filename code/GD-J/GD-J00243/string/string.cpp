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
deque<pair<int,char>>dq;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char ch;
		cin>>x>>ch;
		dq.pb(x,ch);
	}
	int ans=0;
	while(dq.size()>1)
	{
		int p=min(dq.front().fi,dq.back().fi);
		if(dq.front().se!=dq.back().se) ans+=p;
		dq.front().fi-=p,dq.back().fi-=p;
		if(!dq.front().fi) dq.ppf();
		if(!dq.back().fi) dq.ppb();
	}
	cout<<ans;
	return 0;
}
/*
8:52 AC T2

我应该算是比较好写的写法了？
*/