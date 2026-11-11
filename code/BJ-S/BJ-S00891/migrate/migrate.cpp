#include <bits/stdc++.h>

using i64 = long long;

const int MAXN = 2e6 + 5;

int c, t;
int n;
i64 d;
i64 x[MAXN];
int f[MAXN];//以某个点为起点，到达其他点所需要的最小飞行次数,显然可以单调dp
i64 dp[MAXN];//表示以某个点为起点，以最小飞行次数到达其他节点的方案数量
i64 pre[MAXN];//在更新的时候的前缀和数组，辅助更新dp

void solve(){
    std::cin >> n >> d;
    for(int i = 1; i <= n; ++i){
        std::cin >> x[i];
    }

    if((c == 11) || (c == 12)){
        i64 D = x[2] - x[1];
        if(d < 2 * D){
            std::cout<< 0 << '\n';
        }else{
            i64 tms = d / D;
            std::cout << std::max(i64(n) - (tms * 2 - 1), i64(0)) << '\n';
        }
        return;
    }
    if((c == 13) || (c == 14)){
        if(x[n] - x[1] <= d){
            std::cout << 0 << '\n';
        }else{
            int p = 0;
            for(int i = 1; i <= n; ++i){
                if(x[i] == x[1] + d){
                    p = i;
                    break;
                }
            }
            int cnt = 0;
            if((p + 1 <= n) && (p - 2 >= 1) && (x[p + 1] - x[p - 2] > d)){
                ++cnt;
            }
            if((p - 1 >= 1) && (p + 2 <= n) && (x[p + 2] - x[p - 1] > d)){
                ++cnt;
            }
            std::cout << cnt << '\n';
        }
        return;
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i){//考虑(u, v)中以i为起点的所有
        for(int j = 0; j <= n + 1; ++j){
            f[j] = n + 1;
            dp[j] = 0, pre[j] = 0;
        }
        f[i] = 0;
        int p = i, R = i;//p代表当前双指针的左端点,R代表由i可以飞到的所有节点的最右侧
        for(int j = i + 1; j <= n; ++j){
            while(x[p] + d < x[j]){
                ++p;
            }
            if(p == j){//此时说明有不联通的部分
                break;
            }
            f[j] = f[p] + 1;
            R = j;
        }
        //需要使用双指针更新dp,其中pl表示目前双指针左侧,pr表示目前双指针右侧,pl, pr之间的所有节点k可以用来更新最新的节点
        //同时使用一个前缀和来维护
        //注意到当某个节点的dp大于2的时候，这个节点失效，设置为0
        dp[i] = 1;
        pre[i] = 1;
        int pl = i, pr = i;
        for(int j = i + 1; j <= R; ++j){
            while(f[pr + 1] < f[j]){
                ++pr;
            }
            while(f[pl] < f[j] - 1 || x[pl] + d < x[j]){
                ++pl;
            }
            dp[j] = pre[pr] - pre[pl - 1];
            if(dp[j] > 2){
                dp[j] = 0;
            }
            pre[j] = pre[j - 1] + dp[j];
            if(dp[j] == 2){
                //std::cout << i << ' ' << j << '\n';
                ++cnt;
            }
        }
    }
    std::cout << cnt << '\n';
    return;
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin >> c >> t;
    while(t--){
        solve();
    }
    return 0;
}