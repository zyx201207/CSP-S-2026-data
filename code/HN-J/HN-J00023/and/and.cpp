#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 1;

int n, m;
int a[N];

namespace S1{
    int ans = 0;
    void dfs(int x, int y, int num){
        if(y > m) return ;
        if(x == n + 1){
            if(y == m) ans = max(ans, num);
            return ;
        }
        dfs(x + 1, y + 1, (y ? num & a[x] : a[x]));
        dfs(x + 1, y, num);
    }
    void Solve(){
        ans = 0;
        dfs(1, 0, 0);
        cout << ans;
    }
}

namespace Sp1{
    void Solve(){
        int ans = a[1];
        for(int i = 2; i <= n; i++){
            ans &= a[i];
        }
        cout << ans;
    }
}

namespace Sp2{
    void Solve(){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans = max(ans, a[i]);
        }
        cout << ans;
    }
}

namespace Sp3{
    void Solve(){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
    }
}

namespace S2{
    const int LN = 31;
    void Solve(){
        int ans = 0;
        vector<int> num, num2;
        for(int i = 1; i <= n; i++) num.push_back(a[i]);
        for(int i = LN; i >= 0; i--){
            for(int j = 0; j < num.size(); j++) if(num[j] >> i & 1) num2.push_back(num[j]);
            if(num2.size() >= m){
                ans += 1 << i;
                num = num2;
            }
            num2.clear();
        }
        cout << ans;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(m == n) Sp1::Solve();
    else if(m == 1) Sp2::Solve();
    else if(m == 2) Sp3::Solve();
    else if(n <= 20) S1::Solve();
    else S2::Solve();
    return 0;
}
