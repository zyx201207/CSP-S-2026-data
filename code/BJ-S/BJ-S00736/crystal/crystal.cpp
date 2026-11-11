#include <bits/stdc++.h>
#include <cassert>
#define rept(i,a,b) for(int i(a);i<=(b);++i)
#define pert(i,a,b) for(int i(a);i>=(b);--i)
#define rep(i,a,b) for(int i(a);i<(b);++i)
#define per(i,a,b) for(int i(a);i>(b);--i)
#define ls(p) ((p)<<1)
#define rs(p) ((p)<<1|1)
#define lowbit(p) ((p)&-(p))
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
#define me(x,y) memset(x,y,sizeof(x))
#define int long long
#define ull unsigned long long
#define uint unsigned int
#define db double
#define ldb long double
#define pct __builtin_popcount
#define pctll __builtin_popcountll
#define clz __builtin_clz
#define clzll __builtin_clzll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll
using namespace std;
constexpr int N=5e5+5;
int a[N],s[N];
int n,m,ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    rept(i,1,n){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    // 显然只能加，设每次操作的集合为S，那么S中最大的一个数一定不用加
    // 枚举最大值，双指针扫一遍
    // O(nlogn)排序
    rept(i,1,n) s[i]=s[i-1]+a[i];
    int l=1,r=1;
    while(true){
        ans=max(ans,r-l+1);
        ++r;
        if(r>n) break;
        while(a[r]*(r-l+1)-(s[r]-s[l-1])>m) ++l;
    }
    cout<<ans;
    return 0;
}
