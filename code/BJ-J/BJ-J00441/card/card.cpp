#include <iostream>
#include <cstring>
using namespace std;

int a[514514];
bool vis[514514];

signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    memset(vis, 0, sizeof(vis));
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        vis[a[i]] = true;
    }
    for (int i = 1; i <= m; i++){
        int cnt = 0;
        for (int k = 1; k <= n; k++)
        for (int j = k; j <= n; j++){
            if (a[j] == i){
                cnt++;break;
            }
        }
        cout << cnt << ' ';
    }
    return 0;
}