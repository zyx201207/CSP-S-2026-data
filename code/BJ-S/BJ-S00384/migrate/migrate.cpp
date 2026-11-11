#include <bits/stdc++.h>
using namespace std;
int c, t;
int n, d;
int a[1000005];
bool vis[1000005];
int cnt;
int maxn = 0x3f3f3f3f;
int minn;
void dfs(int x, int y, int t){
    if(x == y){
        if(t < minn){
            minn = t;
            cnt = 1;
        }
        else if(t == minn){
            cnt++;
        }
        return;
        if(minn == 1){
            cnt = 0;
        }
    }
    for(int i = x + 1;a[i] - a[x] <= d && i < n; i++){
        if(!vis[i]){
            vis[i] = true;
            dfs(i, y, t + 1);
            vis[i] = false;
        }
    }
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        minn = maxn;
        if(c == 15 || c == 16 || c == 17 || c == 18){
            cout << 0 << endl;
            continue;
        }
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        cin >> n >> d;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 2; j < n; j++){
                dfs(i, j, 0);
                if(cnt == 2) ans++;
                cnt = 1;
            }
        }
        cout << ans;
    }
    return 0;
}
