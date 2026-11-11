#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'

const int maxn = 1e6 + 10, mod = 998244353;
const int inf = 1e9;

int c;
int n;
ull d;
ull a[maxn];
pair<int, int> dp[310][310];

void Init(){
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            dp[i][j] = {0, 0};
        }
    }
}

void solve1(){
    for(int i = 1; i <= n - 1; i ++){
        for(int j = i + 1; j <= n; j ++){
            if(a[j] - a[i] <= d) dp[i][j] = {1, 1};
            else dp[i][j] = {0, inf};
        }
    }
    for(int len = 2; len <= n; len ++){
        for(int l = 1; l <= n - len + 1; l ++){
            int r = l + len - 1;
            int minn = inf;
            if(dp[l][r].first == 1) {
                continue;
            }
            for(int i = l + 1; i <= r - 1; i ++){//
                if(a[i] - a[l] > d) break;
                minn = min(minn, dp[i][r].second + 1);
            }
            for(int i = l + 1; i <= r - 1; i ++){
                if(a[i] - a[l] > d) break;
                
                if(dp[i][r].second + 1 == minn){
                    
                    dp[l][r].first += dp[i][r].first;
                    if(dp[l][r].first > 2) dp[l][r].first = 3;
                }
            }
            dp[l][r].second = minn;
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n - 1; i ++){
        for(int j = i + 1; j <= n; j ++){
            if(dp[i][j].first == 2){
                ans ++;
            }
        }
    }
    cout << ans << endl;
}

void solve(){
    
    cin >> n >> d;
    Init();
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    
    if(c <= 6) solve1();
    //else solve2();
}

int main(){

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> c >> t;
    while(t --) solve();

    return 0;
}
