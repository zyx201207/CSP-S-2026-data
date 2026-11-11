// 好像可以长剖？
// 二分过后感觉相当卡啊
// 感觉二分是去不掉的
// 这东西长剖细节有点多啊
// /tuu
// 又是 3+1
// 把直径取出来，然后再做
// 我现在严重怀疑我会被卡常数
// 我讨厌精细实现！！！！
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
fv slv();int main(){freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
ur();int t=ur();W(t--)slv();return 0;}
constexpr int N = 1e6 + 5, M = N * 2;
int hd[N], fa[N], nx[M], ve[M], tot;
fv ae(int u, int v) {
  nx[++tot] = hd[u], ve[hd[u] = tot] = v;
  nx[++tot] = hd[v], ve[hd[v] = tot] = u;
}
int mx[N], sn[N]; fv dfs(int x, int f) { mx[x] = 0, sn[x] = 0; F(int i = hd[x], y; i; i = nx[i]) if ((y = ve[i]) != f) { dfs(y, x); if (mx[x] <= mx[y]) mx[x] = mx[y] + 1, sn[x] = y; } }
int dfn[N] ,ri[N], cnt;
fv dfs1(int x, int f) { const int h = dfn[x] = cnt++; if (sn[x]) fa[cnt] = h, dfs1(sn[x], x); F(int i = hd[x], y; i; i = nx[i]) if ((y = ve[i]) != f && sn[x] != y) fa[cnt] = h, dfs1(y, x); ri[h] = cnt; }
int f2[N]; int dn[N], di[N];
fv slv() {
  int n = ur(), k = ur(); assert(n >= 2 && k >= 2); mset(hd + 1, 0, n << 2), tot = 0; if (k == n) { std::cout << "0\n"; return; } U(i, 1, n) ae(ur(), ur());
  { dfs(1, 0); int o = 1; W(sn[o]) o = sn[o]; dfs(o, 0), cnt = 1, dfs1(o, 0); }
  fa[n + 1] = 0; R(i, n, 1) dn[i] = fa[i + 1] == i ? dn[i + 1] : i, di[i] = dn[i] - i;
  mset(hd + 1, 0, n << 2);
  auto ae = [&](int u, int v) { nx[v] = hd[u], hd[u] = v; };
  L(i, 1, n) f2[i] = {};
  R(i, n, 1) if (fa[i] != i - 1) ae(fa[i], i), uhi(f2[fa[i]], di[i] + 1);
auto chk = [&](int val) -> bool {
  static int a[N], b[N], c[N];
  auto clr = [&](int *x) { mset(x, 0x3f, n + 5<< 2); }; clr(a), clr(b), clr(c);
  R(x, n, 1) { a[x] = 1; if (dn[x] != x) { if (di[x + 1] >= val) a[x] += a[x + 1]; F(int y = hd[x]; y; y = nx[y]) if (di[y] >= val) a[x] += a[y]; } }
{
  static int t[N];
  struct Vec { int l, r; fv p(int v) { t[--l] = v; } fv reduce(int x, int d, int *b) { uhi(d, -1); W(r - l > d) ulo(b[x], t[r--]); } fv upd(Vec x) { if (r - l < x.r - x.l) std::swap(*this, x); L(i, x.l, x.r) ulo(t[i - x.l + l], t[i]); } };
  static Vec rg[N];
{
  R(x, n, 1) {
    rg[x] = fa[x + 1] == x ? rg[x + 1] : Vec{x+1,x}; rg[x].reduce(x + 1, val - f2[x]-1,b);
    F(int y = hd[x]; y; y = nx[y]) rg[y].reduce(y, val - di[x]-1,b), rg[x].upd(rg[y]); rg[x].p(a[x]);
  }
  rg[1].reduce(1, -1,b); L(i, 2, n) ulo(b[i], b[fa[i]]);
}
{
  L(x, 1, dn[1]) { a[x] = 1; if (x - 2 >= val) a[x] += a[x - 1]; F(int y = hd[x]; y;  y = nx[y]) if (di[y] >= val) a[x] += a[y]; }
  R(x, n, dn[1] + 1) {
    rg[x] = fa[x + 1] == x ? rg[x + 1] : Vec{x+1,x}; rg[x].reduce(x + 1, val - f2[x]-1,c);
    F(int y = hd[x]; y; y = nx[y]) rg[y].reduce(y, val - di[x]-1,c), rg[x].upd(rg[y]); rg[x].p(a[x]);
  }
  L(x, 1, dn[1]) {
    rg[x] = x > 1 ? rg[x - 1] : Vec{dn[1]-x+2,dn[1]-x+1}, rg[x].reduce(x - 1, val - 1 - f2[x],c);
    F(int y = hd[x]; y; y = nx[y]) rg[y].reduce(y, val - (x-1) - 1,c), rg[x].upd(rg[y]); rg[x].p(a[x]);
  }
  rg[dn[1]].reduce(dn[1], -1,c);
  R(i, dn[1], 2) ulo(c[i - 1], c[i]);
  L(i, dn[1] + 1, n) ulo(c[i], c[fa[i]]);
  if (b[1] <= k) return 1; L(i, 2, dn[1]) if (c[i - 1] + b[i] <= k) return 1;
}
  // assert(dn[1] > val * 2 + 2);
}
  static bool use[N]; int all = 0;
  L(i, 1, dn[1]) use[i] = std::max({i - 1, dn[i] - i,f2[i]}) >= val;
  L(i, dn[1] + 1, n) use[i] = di[i] >= val; L(i, 1, n) all += use[i];
  struct DS { int f, e; fv reset(int p) { f = e = p - 1; } fv pop(int v) { f = std::max(f, v); } };
  static DS ds;
  L(i, dn[1] + 1, n) if (use[i]) {
    if (fa[i] != i - 1) ds.reset(i - 1);
    ds.pop(i - (val - f2[i]));
    b[i] -= a[i] - (ds.e - ds.f);
    if (b[i] + all <= k) return 1;
  }
  return false;
};
  int l = 1, r = n;
  W(l != r) if (chk(l + r >> 1)) r = l + r >> 1; else l = (l + r >> 1) + 1; std::cout << l << '\n';
}
