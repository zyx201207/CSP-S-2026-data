#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int a[N] , ans[N] , vis[N];
int n , m , sum = 0;
signed main () {
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int i = 1 ; i <= n ; i++) {
        int maxx =0;
        for(int j = 1 ; j <= m ; j++) vis[j] = 0;
        for(int j = i ; j <= n ; j++) {
            if(vis[a[j]]) {
                for(int z = vis[a[j]] ; z <= maxx ; z++) {
                    if(vis[a[z]]) ans[a[z]] -= 1;
                    vis[a[z]] = 0;
                }
            }
            ans[a[j]]++;
            vis[a[j]] = j;
            maxx = max(maxx , j);
        }
    }
    for(int i = 1 ; i <= m ; i++) cout << ans[i] << " ";
    return 0;
}
