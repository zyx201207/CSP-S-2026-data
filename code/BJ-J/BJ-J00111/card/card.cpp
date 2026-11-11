#include<bits/stdc++.h>
using namespace std;
int a[500005];
int t[300005];
bool vis[3005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(vis[a[j]]){
                memset(vis, 0, sizeof(vis));
            }
            vis[a[j]] = true;
        }

        for(int k = 1; k <= m; k++){
            if(vis[k]) t[k]++;
        }
        memset(vis, 0, sizeof(vis));
    }
    for(int i = 1; i <= m; i++){
        cout << t[i] << " ";
    }
}
