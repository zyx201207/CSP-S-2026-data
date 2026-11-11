#include<bits/stdc++.h>
bool Mbe;
#define il inline
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
template<typename tt> il bool cmax(tt&x, const tt&y) {return x<y?x=y,1:0; }
template<typename tt> il bool cmin(tt&x, const tt&y) {return y<x?x=y,1:0; }
#define sz(x) ((int)x.size())
#define pub push_back
const int N=2e6; 
int n, lst[N+3], nxt[N+3]; ll D,a[N+3];
il int len(int l, int r) { return r-l+1; }
il void S1_solve() {
    ll ans=0;
    for (int u=1; u<=n; ++u) {
        int c=u,d=nxt[u], tot[4]={0,0,0,0};
        for (int v=nxt[u]+1; v<=n; ++v) {
            tot[min(len(lst[v],nxt[c]),3)]++;
            if (tot[2]==1&&tot[3]==0) ++ans;;//, cerr << u << ' ' << v << ' ' << tot[1] << ' ' << tot[2] << ' ' << tot[3] << endl;
            tot[min(len(lst[v],nxt[c]),3)]--;
            if (v==nxt[d]) tot[min(len(lst[v],nxt[c]),3)]++, c=d, d=v;  // cerr << "!" << ' ' << len(lst[v],nxt[c]) << endl, 
            if (nxt[v]==v) break;
        }
    }
    cout << ans << '\n';
}
il int Cnt(int l, int r, int x) {return 
cmin<int>(++r,upper_bound(lst+1,lst+1+n,x)-lst), 
cmax<int>(  l,lower_bound(lst+1,lst+1+n,x)-lst), max(r-l,0); }
il void solve() {
    cin>>n>>D;  
    for (int i=1; i<=n; ++i) cin>>a[i];
    for (int i=1; i<=n; ++i) {
         nxt[i]=int( upper_bound(a+1,a+1+n,a[i]+D)-a-1 );  // r]
         lst[i]=int( lower_bound(a+1,a+1+n,a[i]-D)-a ); // [l, 
    }
    ll ans=0;
    // cerr; for (int i=1; i<=n; ++i) cerr << lst[i] << ' ';; cerr << endl;
    // cerr; for (int i=1; i<=n; ++i) cerr << nxt[i] << ' ';; cerr << endl;
#ifndef MYFRE
    if (n<=5000) return S1_solve(), void();
#endif
    for (int u=1; u<=n; ++u) {
        int c=u,d=nxt[u], tot[4]={0,0,0,0};
        for (int v=nxt[d]; v!=d; ) {
            // cerr << u << ' ' << c << ' ' << d << ' ' << v << ' ' << ans << ": " << endl;
            if (nxt[d]==d) break;
            if (tot[3]) break;
            if (tot[2]==0) {
                // cerr << " " << Cnt(d+1, nxt[d], nxt[c]-1) << endl;
                ans+=Cnt(d+1, nxt[d], nxt[c]-1);
                // Cnt(d+1, nxt[d], nxt[c]-1)?cerr << u << ' ' << c << ' ' << d << ' ' << v << endl,1:0;
            } else if (tot[2]==1) {
                ans+=Cnt(d+1, nxt[d], nxt[c]);
                // Cnt(d+1, nxt[d], nxt[c])?cerr << u << ' ' << c << ' ' << d << ' ' << v << endl,1:0;
            } else break;
            // cerr << "then: " << ans << endl;
            tot[min(len(lst[v],nxt[c]),3)]++, c=d, d=v, v=nxt[d];
        }
    }
    cout << ans << '\n';
}
bool Men;
int main() {
// g++ migrate.cpp -o migrate.exe -O2 -std=c++14 -Wall -Wextra -Wconversion -Wshadow -DMYFRE
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef MYFRE
    cerr << "C migrate" << endl;
    cerr << "C migrate" << endl;
    cerr << "C migrate" << endl;
    cerr << "M: " << (db)(&Mbe-&Men)/1024.0/1024 << endl;
#else
#endif 
    freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
    // solve();
    // int testtt; cin>>testtt; for (int ti=1; ti<=testtt; ++ti) solve();
    int testid, testtt; cin>>testid>>testtt; for (int ti=1; ti<=testtt; ++ti) solve();
#ifdef MYFRE
    cerr << "T: " << (db)clock()/CLOCKS_PER_SEC << endl;
#endif 
}
/*

08子 T1 thk
08丑 T1 thk end
08寅 T2 thk 
08卯 T2 thk 
08辰 T2 thk 
08巳 T2 thk 
08午 T1, T2 chk
08未 emp 精力：一般偏低; 杂念：-; 心情：一般偏上 [耳虫 ]悲凉; 行动力：一般;
08申 T3 thk
08酉 T3 thk 精力：一般偏低; 杂念：一般; 心情：一般偏下 T3 ing; 行动力：一般;
08戌 T4 thk
08亥 T4 thk 

09子 T1 code [食]
09丑 T1 code 杂念：高[ai];
09寅 T1 debug sp3WA 疑似二分范围有误
09卯 T1 debug fail
09辰 T1 bao WA 重新读题 T1 spAC
09巳 T1 pai
09午 T1 pai
09未 T2 thk 杂念：[耳虫]狂，电音
09申 T2 code 灵光一现
09酉 T2 code
09戌 T2 code end sp1WA
09亥 T2 debug end

10子 T2 chk end
10丑 emp 精力：一般; 杂念：[耳虫]狂，电音; 心情：一般; 行动力：一般;
10寅 T3 thk [食]
10卯 T3 thk
10辰 T3 thk  精力：低 [困]; 杂念：[耳虫]狂，电音; 心情：一般; 行动力：低;
10巳 T3 thk bao [食]
10午 T4 thk
10未 emp
10申 T4 thk
10酉 T4 thk
10戌 T4 code
10亥 T4 code 精力：低 [困]; 杂念：[ai]

11子 T4 code
11丑 T4 code
11寅 T4 debug [困]
11卯 T4 debug [困]
11辰 T4 debug end sp3WA
11巳
11午
11未
11申
11酉 T3 bao end
11戌
11亥

## T1

bi + tr + pll + rem

错， bi + 前缀和 + rem

记得sort, ll

题意读错只有增加 -15min

## T2

直接 n/2 次 dj??

d<=20 (<=n)点周围([n+1,m ])的点数有限

\sum d = \sum k <= 1e4 

考虑直接遗弃 k == 1 的 地铁站

此后 250次dj  

注意空间，只存有用的东西，E 开 > 1e6 N 开 >1e6 演一下

地铁是双向任意通行

读错题：询问的是 <=5e5

此时应当枚举d

2.5e9 应该可以吧

考虑对于每个 m， 可以连出 d^2 条边，直接floyd  2e8

## T3 

小数数

答案是偶数 u< v or u >v

注意：可以绕路？要求最短！

考虑变成i [l_i, r_i] 但距离足够小可能有其他性质

最短路恰好两条；考虑IE / 找性质

可以n次dj, 线段树优化建图 n^2log(n)

2e6????

考虑如何求最短路 a+k*d?? 不对 考虑dp？ 考虑固定右端点？？

主席树？

最短路要求每次跳得尽量远

考虑相同远的情况但落点不同之多几个？？

dis=1 则不存在多种答案

dis=2 恰好两个不同位点，则这两个位点相邻 （sub13）

    a,b,c,d,e,f

    c-a <= D d-a<=D e-a>D

    f-d<=D f-c<=D f-b>D

    d1+d2+d3 <=D d1+d2+d3+d4>D

    d3+d4+d5 <=D d2+d3+d4+d5>D

    考虑枚举 i,i+1 找到临界点即可

    二分确定a,f 的位置

    注意判断 是否可达，是否是两步

dis=3 

    恰好偏移一个位置  则dis2 的情况+只能极限跳

    但只能极限跳也难以刻画; 考虑？？

    考虑假设存在连续两个点 和极限跳方案中不同 则 > 2

    考虑假设存在不连续两个点 和极限跳方案中不同 则 > 2

    因此还是只能有一个不同



考虑只有一种路径的情况：

考虑不止一种路径的情况：

考虑答案范围：  
    
    是不是很少？第一次出现两种路径，第二次出现两种路径 

    <=n 还是 j \in [lw_i, up_i]?

考虑差分化?

特殊性质A,B

A:等差数列则若干相同子问题

B:无敌岛屿在中间 len <= 2 

C:考虑枚举路径长度

不可能回跳

用lst,nxt [] 刻画  

就是 \exits only one rg_i,rg_{i+2} 交点恰好=2，其他全部=1

先包里，在ds


## T4 

考虑二分答案？？

2e6??

树上相邻？？点分治？？树剖？dp?

两个连通块：在树上断开一条边？树上圆理论？重心？边变成点？

连通块：点边？染色？sgt?赋权？缩成一点？

先单独处理一个连通块

不能直接中间劈开，可能连通块中心点选的丑

特殊性质: 蜈蚣

考虑 两个连通块-> 一个连通块

先找到直径中点/中间边 

中间边直接缩掉

然后缩掉最长链，但最长链不唯一

用堆实现

枚举树上的断边，直接做

如果n > 1000/4000 则考虑只段原树直径中间e*/