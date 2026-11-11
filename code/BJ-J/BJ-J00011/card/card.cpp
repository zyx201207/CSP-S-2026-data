#include <bits/stdc++.h>
using namespace std;
int a[500010], b[500010], c[500010];
int vis[500010];
int cnt[500010];
        int first[500010];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = 1;i <= n;i++){
            int t= 1;
        for(int j = i;j <= n;j++){
            if(vis[a[j]] == 0){
                vis[a[j]] = 1;
                b[t] = a[j];
                t++;
            }
            else {
                int q = lower_bound(b + 1, b + 1 + n,a[j]) - b;
                for(int k = 1;k <= q;k++){
                    c[k] = b[k];
                }
                b[500010] = {0};
                c[q + 1] = a[j];
            }
        }
        for(int z = 1;z <= n;z++){
            if(first[c[z]] == 0)cnt[c[z]]++;
            first[c[z]] = 1;
        }
        first[500010] = {0};
    }
    for(int i = 1;i <= m;i++){
        cout << cnt[i];
        cout << " ";
    }
    return 0;
}