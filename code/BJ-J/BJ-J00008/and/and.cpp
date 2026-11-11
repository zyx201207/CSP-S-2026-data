#include<bits/stdc++.h>
using namespace std;
int n , m;
int dp[2005][2005];
int a[2005];
int maxn = -1;
int vis[2005];
void dfs(int s, int ans , int last) {
    if(s == m + 1) {
        if(ans > maxn) {
            maxn = ans;
        }
        return ;
    }
    for(int i = 0;i < n;i++) {
        if(a[i] >= last && vis[i] == false) {
            vis[i] = true;
            dfs(s + 1 , ans & a[i] , a[i]);
            vis[i] = false;
        }
    }
}
int main() {
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(a , a + n);
    for(int i = 0;i < n;i++) {
        dfs(1 , a[i] , -1);
    }
    cout << maxn;
    return 0;
}
