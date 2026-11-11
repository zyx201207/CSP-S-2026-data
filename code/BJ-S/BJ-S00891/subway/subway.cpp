#include <bits/stdc++.h>

using i64 = long long;

const int MAXM = 5e5 + 5, MAXN = 505;

int c, n, m, d, q;
i64 w[MAXM];
int k[MAXN];//标记k号线路的站台数量
struct node{
    int lines, sta, time;
}P[MAXM];//标记某个站台，表示该站台属于地铁line线路，通向站厅的时间为time, 站厅属于sta号车站
int tot = 0;//记录总的站台数量
int cntline[MAXM];//用来存储某个站台拥有的线路的数量
int fst[MAXM];//用来记录某个车站在排序后第一次出现的位置
i64 dp[MAXN][MAXN];//用来标记从某个地铁线路的车上到另一个地铁线路的车上所需要的最小时间，初始值由某个站台初始化得到
int X[MAXM], Y[MAXM];

i64 solve(int st, int ed){
    i64 ret = 2e18;
    //std::cout << st << ' ' << ed << '\n';
    for(int i = fst[st]; i <= fst[st] + cntline[st] - 1; ++i){
        for(int j = fst[ed]; j <= fst[ed] + cntline[ed] - 1; ++j){
            ret = std::min(ret, dp[P[i].lines][P[j].lines] + i64(P[i].time + P[j].time));
            //std::cout << P[i].lines << ' ' << P[j].lines << ' ' << ret << '\n';
        }
    }
    return ret + w[st] + w[ed];
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; ++i){
        std::cin >> w[i];
    }
    int tmpa = 0, tmpt = 0;
    for(int i = 1; i <= n; ++i){
        std::cin >> k[i];
        for(int j = 1; j <= k[i]; ++j){
            std::cin >> tmpa >> tmpt;
            P[++tot] = {i, tmpa, tmpt};
            ++cntline[tmpa];
        }
    }
    for(int i = 1; i <= q; ++i){
        std::cin >> X[i] >> Y[i];
    }

    std::sort(P + 1, P + 1 + tot, [&](node x, node y){
        return x.sta < y.sta;
    });
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            dp[i][j] = 2e18;
        }
    }
    for(int i = 1; i <= n; ++i){
        dp[i][i] = 0;
    }
    for(int i = 1; i <= tot; ++i){//初始化dp
        if(P[i].sta == P[i - 1].sta){
            continue;
        }
        fst[P[i].sta] = i;
        for(int x = i; x <= i + cntline[P[i].sta] - 1; ++x){
            for(int y = x + 1; y <= i + cntline[P[i].sta] - 1; ++y){
                dp[P[x].lines][P[y].lines] = std::min(dp[P[x].lines][P[y].lines], i64(P[x].time + P[y].time));
                dp[P[y].lines][P[x].lines] = dp[P[x].lines][P[y].lines];
            }
        }
    }
    for(int x = 1; x <= n; ++x){//线路换乘最短时间
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                dp[i][j] = std::min(dp[i][j], dp[i][x] + dp[x][j]);
            }
        }
    }

    for(int i = 1; i <= q; ++i){
        std::cout << solve(X[i], Y[i]) << '\n';
    }
    return 0;
}