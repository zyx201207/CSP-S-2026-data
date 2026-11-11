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
constexpr int N=5e3+10;
int n,d,ans,x[N],to[N],dis[N][N],cnt[N][N];
// dis[l][r]：l->r距离
void sub(int l,int r){
    for(int i=l,j=i;i<=r;++i){
        while(j+1<=r&&x[j+1]-x[i]<=d) ++j;
        to[i]=j;
    }
    pert(i,r,l){
        dis[i][i]=0;
        rept(j,i+1,to[i]) dis[i][j]=1;
        rept(j,to[i]+1,r) dis[i][j]=dis[to[i]][j]+1;
        cnt[i][i]=1;
        rept(j,i+1,r){
            cnt[i][j]=0;
            pert(k,to[i],i+1){
                if(dis[i][k]+dis[k][j]==dis[i][j]) cnt[i][j]+=cnt[k][j];
                else break;
                if(cnt[i][j]>2) break;
            }
        }
        rept(j,i+1,r) ans+=cnt[i][j]==2;
    }
}
void solve(){
    cin>>n>>d;
    ans=0;
    rept(i,1,n) cin>>x[i];
    // 保证a严格递增
    // 显然，从i->j(i<j)的所有最短路径不会走回头路
    // 显然，i,i+1距离>d的位置把序列划分成独立子问题，因为鸟不可能越过该位置
    // 在一个子问题内，如何求出最短路？
    // 贪心地每次向后跳最多显然是最短路
    // 那么何时会恰好有一个非贪心最优解？
    // 枚举起点，我们已经有40pts
    // 接下来考虑贪心过程
    // 显然dis具有单调性，左端点左移/右端点右移使得dis单调增加
    // 可以O(n^2)处理出所有点对dis
    // ......
    // 问题转化为如何快速判断一段的dp[l][r]==1->dp[l][r]==2
    int l=1;
    rept(i,2,n) if(x[i]-x[i-1]>d){
        sub(l,i-1),l=i;
    }
    sub(l,n);
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int c,T;
    cin>>c>>T;
    while(T--) solve();
    return 0;
}