#include <iostream>
using namespace std;
const int N = 2e5 +5;
int maxi, n, m;
bool vis[N];
int a[N];
int check() {
    int ans = 0;
    bool flag = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i]) {
            if(!flag) {
                flag = 1;
                ans = a[i];
            }
            ans &= a[i];
        }
    }
    return ans;
}
void dfs(int num, int x) {
    if(num == m) {
        maxi = max(maxi, check());
    }
    if(x == n) {
        return;
    }
    dfs(num, x + 1);
    vis[x +1] = 1;
    dfs(num + 1, x +1);
    vis[x + 1] = 0;
}
int main()
 {
     freopen("and.in", "r", stdin);
     freopen("and.out", "w", stdout);
     cin >> n >> m;
     int ans1 = 0, maxx = 0;
     for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(m == n) {
            if(i == 1) {
                ans1 = a[i];
            }
            ans1 &= a[i];
        }
        maxx = max(maxx, a[i]);
     }
     if(m == n) {
        cout << ans1;
        return 0;
     }
     if(m == 1) {
        cout << maxx;
        return 0;
     }
     dfs(0, 0);
     cout << maxi;
     return 0;
 }
