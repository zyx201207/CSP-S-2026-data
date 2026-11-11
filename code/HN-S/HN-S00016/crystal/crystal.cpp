#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 5e5 + 1;

bool A = 1, B = 1;
int n;
ll a[N], m;

namespace SpA{
    void Solve(){
        ll ans = 0;
        for(int i = 1; i <= n; i++) if(i * (i + 1) / 2 <= m) ans = i;
        cout << ans + 1;
    }
}

namespace S1{
    int ans;
    void dfs(int i, ll mx, ll add, int cnt){
        if(i == n + 1){
            if(mx * cnt - add <= m) ans = max(ans, cnt);
            return ;
        }
        dfs(i + 1, mx, add, cnt);
        dfs(i + 1, max(mx, a[i]), add + a[i], cnt + 1);
    }
    void Solve(){
        ans = 0;
        dfs(1, 0, 0, 0);
        cout << ans;
    }
}

namespace S2{
    void Solve(){
        sort(a + 1, a + 1 + n);
        ll ans = 1;
        for(int i = 2; i <= n - ans; i++){
            ll add = 0;
            for(ll j = i; j <= n; j++){
                add += 1ll * (a[j] - a[j - 1]) * (j - 1);
                if(add <= m) ans = max(ans, j - i + 2);
                else break;
            }
        }
        cout << ans;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != i) A = 0;
    }
    if(A) SpA::Solve();
    else if(n <= 16) S1::Solve();
    else S2::Solve();
    return 0;
}
