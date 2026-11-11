#include <bits/stdc++.h>
using namespace std;

#define finished 1

long long n, m, c, d, q, ki;
long long w[500008];
vector<long long> line[508][3];
long long mp[500008][21], tail[500008];
long long a, t;
long long x, y;
bool vis[500008];

// long long dfs(long long current){
//     long long ans;
//     for(int i = 1; i <= tail[current]; i++){
//         for(int j = 1; j <= line[mp[current][i]][1].size(); j++){
//             if(!vis[k])
//         }
//     }
// }

int main(){
    #if finished
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    #endif
    scanf(" %lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++){
        scanf(" %lld", &w[i]);
    }
    for(int i = 1; i <= n; i++){
        scanf(" %lld", &ki);
        for(int j = 1; j <= ki; j++){
            scanf(" %lld %lld", &a, &t);
            line[i][1].push_back(a);
            line[i][2].push_back(t);
            mp[i][++tail[i]] = a;
        }
    }
    while(q--){
        scanf(" %lld %lld", &x, &y);
        memset(vis, 0, sizeof(vis));
        long long ans = 0;
        ans += w[x] + w[y];
        printf("%lld\n", ans);
    }
    return 0;
}