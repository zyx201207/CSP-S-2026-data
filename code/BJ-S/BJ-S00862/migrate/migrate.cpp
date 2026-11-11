#include<bits/stdc++.h>
using namespace std;

long long c, t, n, d, cnt, min_cost, ans, x[2000001];

void dfs(long long k, long long en, long long cost){
    if(k == en){
        if(cost < min_cost){
            min_cost = cost;
            cnt = 1;
        }
        else if(cost == min_cost){
            cnt++;
        }
        return ;
    }
    if(cost == min_cost){
        return ;
    }
    for(long long i = k + 1; i <= n; i++){
        if(x[i] - x[k] > d){
            return ;
        }
        dfs(i, en, cost + 1);
    }
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        ans = 0;
        cin >> n >> d;
        for(long long i = 1; i <= n; i++){
            cin >> x[i];
        }
        for(long long i = 1; i <= n - 3; i++){
            for(long long j = i + 3; j <= n; j++){
                cnt = 0;
                min_cost = LLONG_MAX;
                dfs(i, j, 0);
                if(cnt == 2){
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}