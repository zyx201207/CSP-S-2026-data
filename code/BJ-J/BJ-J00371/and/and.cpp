#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
int ans, t = 1;

void dfs(int last, int cnt){
    if(cnt >= m) return;
    for(int i = last + 1; i + m - 1 - cnt <= n; i ++){
        if(last == 0) t = a[i];
        else t = t & a[i];
        dfs(i, cnt + 1);
        if(last == 0) ans = max(ans, t);
        //cout << t << "\n";
    }
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    sort(a + 1, a + n + 1);
    //m = 1 5'
    if(m == 1){
        cout << a[n];
        return 0;
    }
    // m = n 5'
    if(m == n){
        ans = a[1];
        for(int i = 2; i <= n; i ++) ans = ans & a[i];
        cout << ans;
        return 0;
    }
    // m = 2 15'
    if(m == 2){
        ans = 0;
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++){
                if(i == j) continue;
                ans = max(ans, a[i] & a[j]);
            }
        cout << ans;
        return 0;
    }

    // n <= 20 25'
    if(n <= 20){
        dfs(0, 0);
        cout << ans;
        return 0;
    }

    //A 5'
    cout << a[n - m + 1];
    return 0;
}
