#include <bits/stdc++.h>
using namespace std;
long long CESHIDIAN, n, m, p, q1, ans2026[500005];//ans2026需要在结束时与答案相加
long long dp[505][505];
struct node{
    long long a, b;
};
priority_queue<node, vector<node>, greater<node> > q;
int operator > (node x, node y){
    return x.b > y.b;
}
vector<long long> w[500005], v[500005], c[505], d[505];
bool vis[505];
void bfs(long long st){
    while(!q.empty()) q.pop();
    for(int i = 1;i <= n;i++) vis[i] = false;
    dp[st][st] = 0;
    q.push(node{st, 0});
    while(!q.empty()){
        node cnt = q.top();
        q.pop();
        if(vis[cnt.a] == true) continue;
        vis[cnt.a] = true;
        for(int i = 0;i < c[cnt.a].size();i++){
            if(d[cnt.a][i] + cnt.b < dp[st][c[cnt.a][i]]){
                dp[st][c[cnt.a][i]] = d[cnt.a][i] + cnt.b;
                q.push(node{c[cnt.a][i], d[cnt.a][i] + cnt.b});
            }
        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld %lld %lld %lld %lld", &CESHIDIAN, &n, &m, &p, &q1);
    for(int i = 1;i <= m;i++){
        cin >> ans2026[i];
    }
    for(int i = 1;i <= n;i++){
        long long x, y, z;
        scanf("%lld", &x);
        while(x--){
            scanf("%lld %lld", &y, &z);
            w[y].push_back(i);
            v[y].push_back(z);
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < w[i].size();j++){
            for(int k = 0;k < j;k++){
                c[w[i][j]].push_back(w[i][k]);
                c[w[i][k]].push_back(w[i][j]);
                d[w[i][j]].push_back(v[i][j] + v[i][k]);
                d[w[i][k]].push_back(v[i][j] + v[i][k]);
            }
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= n;i++) bfs(i);

    for(int i = 1;i <= q1;i++){
        long long x, y, ans = 9e18;
        scanf("%lld %lld", &x, &y);
        for(int j = 0;j < w[x].size();j++){
            for(int k = 0;k < w[y].size();k++){
                ans = min(ans, v[x][j] + v[y][k] + dp[w[x][j]][w[y][k]]);
            }

        }
        printf("%lld\n", ans + ans2026[x] + ans2026[y]);
    }
    return 0;
}