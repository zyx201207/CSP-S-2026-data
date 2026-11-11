#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

int n, m, mx, res;
int a[N];
bool used[N];
int b[N];
bool flag = true;

bool cmp(int x, int y){
    return x > y;
}
void dfs(int pos){
    if(pos == m + 1){
        int sum = a[b[1]];
        for(int i = 1; i <= m; i++){
            sum &= a[b[i]];
        }
        res = max(res, sum);
        return ;
    }
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            used[i] = true;
            b[pos] = i;
            dfs(pos + 1);
            used[i] = false;
        }
    }
}

signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        if(a[i] != (i - 1)) flag = false;
    }
    if(n <= 20){
        dfs(1);
        cout << res;
        return 0;
    }
    if(m == 1){
        cout << mx;
        return 0;
    }
    if(m == 2 && n <= 2000){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                ans = max(ans, (a[i] & a[j]));
            }
        }
        cout << ans;
        return 0;
    }
    if(m == n){
        int ans = a[1];
        for(int i = 2; i <= n; i++){
            ans = (ans & a[i]);
        }
        cout << ans;
        return 0;
    }
    if(m == n - 1){
        int sum = a[1], ans = 0;
        for(int i = 2; i <= n; i++) sum &= a[i];
        for(int i = 1; i <= n; i++) ans = max(ans, (sum & a[i]));
        cout << ans;
        return 0;
    }
    bool ok = false;
    for(int i = 1; i <= 30; i++){
        if(n == pow(2, i)){
            ok = true;
            break;
        }
    }
    if(ok && flag){
        cout << n - m;
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);
    int ans = a[1];
    for(int i = 2; i <= m; i++){
        ans &= a[i];
    }
    cout << ans;
    return 0;
}
