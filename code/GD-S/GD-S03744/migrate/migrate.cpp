#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dfs(int d, vector<ll> lands, int end, int current, int p){
    if (current == end){
        return 1;
    }
    int cnt = 0;
    for (int i = 1; i < end; i++){
        if (abs(lands[current] - lands[current + i]) <= d){
            cnt += dfs(d, lands, end, current + i, p + 1);
        }
    }
    return cnt;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ll c, t = 0;
    cin >> c >> t;
    while(t--){
        ll n, d, ans = 0;
        cin >> n >> d;
        vector<ll> lands(n);
        for (int i = 0; i < n; i++)
            cin >> lands[i];
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (dfs(d, lands, j, i , 1) == 2){
                    ans++;
                }
        cout << ans << endl;
    }
    return 0;
}