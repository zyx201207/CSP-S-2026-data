#include <bits/stdc++.h>
#define getchar getchar_unlocked
#define ll long long
#define endl '\n'
using namespace std;
const int N1 = 5e2 + 10, N2 = 5e5 + 10;
const ll inf = 2e18 + 10;
struct station{
    int pass;
    ll bel[30], trans[30];
} sta[N2];
int n, m, d, q;
ll to_ground[N2];
ll dis[N1][N1];
inline ll read(){
    char c = getchar();
    int flag = 1;
    ll ans = 0;
    while(! (c >= '0' && c <='9')){
        if(c == '-') flag = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ans = (ans << 3) + (ans << 1) + c - '0';
        c = getchar();
    }
    return ans * flag;
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    read();
    n = read(), m = read(), d = read(), q = read();
    fill(&dis[0][0], &dis[0][0] + N1 * N1, inf);
    for(int i = 1; i <= m; i ++) to_ground[i] = read();
    for(int i = 1; i <= n; i ++){
        int num = read();
        for(int j = 1; j <= num; j ++){
            int s = read();
            sta[s].pass ++;
            sta[s].bel[sta[s].pass] = i;
            sta[s].trans[sta[s].pass] = read();
        }
    }
    for(int i = 1; i <= m; i ++)
        for(int p = 1; p < sta[i].pass; p ++)
            for(int q = p + 1; q <= sta[i].pass; q ++)
                dis[sta[i].bel[p]][sta[i].bel[q]] = dis[sta[i].bel[q]][sta[i].bel[p]] = min(dis[sta[i].bel[p]][sta[i].bel[q]], sta[i].trans[p] + sta[i].trans[q]);
    for(int k = 1; k <= n; k ++)
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                if(i - j) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                else dis[i][j] = 0;
    while(q --){
        int x = read(), y = read();
        ll res = inf;
        for(int i = 1; i <= sta[x].pass; i ++)
            for(int j = 1; j <= sta[y].pass; j ++)
                res = min(res, dis[sta[x].bel[i]][sta[y].bel[j]] + sta[x].trans[i] + sta[y].trans[j]);
        cout << res + to_ground[x] + to_ground[y] << endl;
    }
    return 0;
}
