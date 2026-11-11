#include<bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
long long a[M], n, m, tt, maxn, cnt;
bool vis[M];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        memset(vis, 0, sizeof(vis));
        maxn = max(maxn, tt);
        for(int j = i + 1; j <= n; j++){
            if(cnt == m) break;
            if(vis[j]) continue;
            cnt++;
            if(cnt == 1){
                tt = a[j];
                vis[j] = true;
            }
            tt &= a[j];
        }
    }
    cout << maxn;
    return 0;
}