#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e6 + 5;
int n, dis[N], cnt[N];
LL d, x[N];
queue<int> q;
int bfs(int s, int t){
    for(int i = s; i <= t; ++i){
        dis[i] = 1e9;
        cnt[i] = 0;
    }
    q.push(s);
    dis[s] = 0;
    cnt[s] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        LL sum = 0;
        for(int i = u+1; i <= t; ++i){
            sum += x[i] - x[i-1];
            if(sum > d) break;
            if(dis[i] > dis[u] + 1){
                dis[i] = dis[u] + 1;
                cnt[i] = cnt[u];
                q.push(i);
            }
            else if(dis[i] == dis[u] + 1)
                cnt[i] += cnt[u];
        }
    }
    return cnt[t];
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    while(t--){
        scanf("%d%lld", &n, &d);
        for(int i = 1; i <= n; ++i)
            scanf("%lld", &x[i]);
        LL ans = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = i+1; j <= n; ++j){
                if(bfs(i, j) == 2) ans++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}