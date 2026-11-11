#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int N = 5010, M = 500100;
ll read(){
    ll x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void write(ll x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x <= 9){
        putchar(x + '0');
        return;
    }
    write(x / 10);
    putchar(x % 10 + '0');
}

int c, n;
ll d, x[N];

void solve(){
    if(c == 11 || c == 12){
        n = read(), d = read();
        vector<int> x(n + 1);
        for (int i = 1; i <= n; i++){
            x[i] = read();
        }
        if(n == 1){
            puts("0");
            return;
        }
        if(d > x[n] - x[1]){
            puts("0");
            return;
        }
        if(d < x[2] - x[1]){
            puts("0");
            return;
        }
        if(d < 2 * (x[2] - x[1])){
            puts("1");
            return;
        }
        write(n - 2 * d / (x[2] - x[1]) + 1);
        puts("");
        return;
    }
    n = read(), d = read();
    for (int i = 1; i <= n; i++)
        x[i] = read();
    if(n == 1){
        puts("0");
        return;
    }
    if(d > x[n] - x[1]){
        puts("0");
        return;
    }
    if(n <= 300){
        vector<vector<pii>> dp(n + 1, vector<pii>(n + 1, {INT_MAX, 0}));
        int ans = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i; j <= n; j++){
                if(i == j){
                    dp[i][j] = {0, 1};
                    continue;
                }
                for (int k = i; k <= j; k++){
                    if(x[j] - x[k] > d)
                        continue;
                    if(dp[i][j].first > dp[i][k].first + 1){
                        dp[i][j].first = dp[i][k].first + 1;
                        dp[i][j].second = 0;
                    }
                    if(dp[i][j].first == dp[i][k].first + 1){
                        dp[i][j].second += dp[i][k].second;
                    }
                }
                ans += dp[i][j].second == 2;
            }
        }
        write(ans);
        puts("");
    }
}

int main(){
   freopen("migrate.in", "r", stdin);
   freopen("migrate.out", "w", stdout);
    c = read();
    int T = read();
    while(T--){
        solve();
    }
}
