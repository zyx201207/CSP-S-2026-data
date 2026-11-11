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
bool check(char a,char b)
{
	if(a>b) swap(a,b);
	return (a=='A'&&(b=='B'||b=='C'))||(a=='B'&&b=='C')||(a=='D'&&b=='F');
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){cout<<"0000";return 0;}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){cout<<"1000";return 0;}
	if(!check(s1[2],s2[2])){cout<<"1100";return 0;}
	if(abs(s1[2]-s2[2])==1||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) cout<<"1111";
	else cout<<"1110";
	return 0;
}
/*
今年变成 vscode 党了！

是我变强了还是这场简单？

8:36 完成所有题目口胡

8:49 AC T1，配 vscode 花了一段时间

9:24 T1 差点挂分了是什么

关注 Shellchen 谢谢喵。
*/