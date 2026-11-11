#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5 + 10;
int a[maxn], n, m, ans;
void dfs(int cnt, int sum, int i){
    if(cnt == m){
        ans = max(ans, sum);
        return ;
    }
    if(sum == 0) dfs(cnt + 1, a[i], i + 1);
    else dfs(cnt + 1, sum & a[i], i + 1);
    if(m - cnt <= n - i) dfs(cnt, sum, i + 1);
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    bool f = 1, f2 = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i != 1 && a[i] != a[i-1] + 1) f2 = 0;
        int tmp = a[i];
        while(tmp){
            if(tmp % 2 != 0){
                f = 0;
                break;
            }
            tmp /= 2;
        }
    }
    if(m == n - 1){
        int sum = a[1], mx = -1;
        for(int i = 2; i <= n; i++) sum &= a[i];
        for(int i = 1; i <= n; i++) mx = max(mx, (sum & a[i]));
        cout << mx;
        return 0;
    }
    if(f == 1 || f2 == 1){
        sort(a + 1, a + n + 1);
        int sum = a[n];
        for(int i = n - 1; n - i + 1 <= m; i--) sum &= a[i];
        cout << sum;
        return 0;
    }
    dfs(0, 0, 1);
    cout << ans;
    return 0;
}

