// 这个题是不是有点猎奇了。。。
/*
大致就是钦定一下中间的点对，然后瞎统计一下就行了
*/
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
fv slv();int main(){freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
ur();int t=ur();W(t--)slv();return 0;}
fv slv() {
  int n = ur(); i64 d = ur<u64>();
  vi pr(n), nx(n);
{
  vector<i64> a(n); F(auto &x : a) x = sr<i64>();
  int l = 0, r = 0; U(i, 0, n) { W(a[l] + d < a[i]) ++l; W(r < n && a[r] - d <= a[i]) ++r; pr[i] = l, nx[i] = r - 1; }
}
  i64 ans = 0;
{
  vi lc(n), rc(n);
  U(i, 0, n) { ++lc[i]; if (nx[i] > i) if (pr[nx[i]] == i) lc[nx[i]] += lc[i]; else lc[nx[i]] += 1; }
  R(i, n-1, 0) { ++rc[i]; if (pr[i] < i) if (nx[pr[i]] == i) rc[pr[i]] += rc[i]; else rc[pr[i]] += 1; }
  struct Pos { int p; fv move(vi &x, int v, int n) { W(p < n && x[p] < v) ++p; } };
  Pos a{},b{},c{},d{};
  int ll, lr, rl, rr;
  U(i, 1, n) {
    a.move(nx, i, n), b.move(nx, i + 1, n), c.move(pr, i - 1, n), d.move(pr, i, n);
    ll = a.p, lr = std::min(b.p, i - 1), rl = std::max(c.p, i + 1), rr = d.p;
    if (ll < lr && rl < rr) {
      i64 lv = 0, rv = 0;
      U(p, ll, lr) lv += p == pr[i - 1] ? lc[p] : 1;
      U(p, rl, rr) rv += p == nx[i] ? rc[p] : 1;
      ans += lv * rv;
    }
  }
}
  std::cout << ans << '\n';
}
