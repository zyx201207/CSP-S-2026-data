#include<vector>//{{{
#include<cassert>
#include<iostream>
#include<algorithm>
#define F for
#define W while
#define fi first
#define se second
#define fv inline void
#define eb emplace_back
#define fn inline static
#ifdef _WIN32
#define gc _getchar_nolock
#else
#define gc getchar_unlocked
#endif
#define mset __builtin_memset
#define mcpy __builtin_memcpy
#define mmov __builtin_memmove
#define U(i,a,b) F(int i=(a);i<(int)(b);++i)
#define L(i,a,b) F(int i=(a);i<=(int)(b);++i)
#define R(i,a,b) F(int i=(a);i>=(int)(b);--i)
using u8=unsigned char;using u16=unsigned short;using u32=unsigned;using u64=unsigned long long;using u128=__uint128_t;using i8=char;using i16=short;using i64=long long;using i128=__int128_t;using pi=std::pair<int,int>;using pu=std::pair<u32,u32>;using str=std::string;using std::vector;using vu=vector<u32>;using vi=vector<int>;template<typename T,typename... A>fv uhi(T&x,A&&...v){x=std::max(x,T{v...});}template<typename T,typename... A>fv ulo(T&x,A&&...v){x=std::min(x,T{v...});}template<typename T=u32>fn T ur(){u32 c;W(!__builtin_isdigit(c=gc()));T r=c&15;W(__builtin_isdigit(c=gc()))r=(r<<3)+(r<<1)+(c&15);return r;}template<typename T=int>fn T sr(){u32 c;bool f=0;W(!__builtin_isdigit(c=gc()))f=c=='-';T r=c&15;W(__builtin_isdigit(c=gc()))r=(r<<3)+(r<<1)+(c&15);return f?-r:r;}
#if 0
constexpr u32 mod=1e9+7;fv dec(u32&x){if(x>=mod)x-=mod;}fv inc(u32&x){if((int)x<0)x+=mod;}fv add(u32&x,u64 v){x=(x+v)%mod;}fn u32 qpw(u32 x,u32 e){u32 r=e&1?x:1;W(e>>=1){x=(u64)x*x%mod;if(e&1)r=(u64)r*x%mod;}return r;}
#endif//}}}
fv slv();int main(){freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
int t=1;W(t--)slv();return 0;}
fv slv() {
  int n = ur(); i64 m = ur<u64>();
  vector<i64> a(n); F(auto &x : a) x = sr<i64>();
  std::sort(a.begin(),a.end());
  i64 su = 0; int  q = 0, ans = 1;
  U(i, 1, n) {
    su += (i64)(i - q) * (a[i] - a[i - 1]); W(su > m) su -= a[i] - a[q++];
    uhi(ans, i - q + 1);
  }
  std::cout << ans << '\n';
}
