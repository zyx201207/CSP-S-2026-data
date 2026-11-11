#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int a[N];
int n , m , sum = 0 , pos = 0;
void dfs(int id , int num , int ans) {
    if(num == m){
        sum = max(ans , sum);
        return;
    }
    else if(id == n + 1) return;
    if(ans == -1) {
        dfs(id + 1 , num , ans);
        dfs(id + 1 , num + 1 , a[id]);
    }
    else {
        dfs(id + 1 , num , ans);
        dfs(id + 1 , num + 1 , ans &= a[id]);
    }
    return;
}
signed main () {
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    if(m == n) {
        int ans = a[1];
        for(int i = 2 ; i <= n ; i++) ans &= a[i];
        pos = ans;
        cout << ans;
        return 0;
    }
    if(m == 1) {
        int ans = a[1];
        for(int i = 2 ; i <= n ; i++) ans = max(ans , a[i]);
        cout << ans;
        return 0;
    }
    dfs(1 , 0 , -1);
    cout << sum;
    return 0;
}