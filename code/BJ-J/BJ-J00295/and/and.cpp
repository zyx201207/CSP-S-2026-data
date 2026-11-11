#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int a[N];
bool vis[N];

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(m == 1){
        sort(a+1, a+1+n);
        cout << a[n];
        return 0;
    }
    if(n==m){
        int ans = a[1];
        for(int i = 2; i <= n; i++){
            ans = (ans&a[i]);
        }
        cout << ans;
        return 0;
    }
    int ans = 0;
    int p, q;
    for(int j = 1; j <= n; j++){
        for(int k = j + 1; k <= n; k++){
            if((a[j]&a[k]) > ans){
                ans = (a[j]&a[k]);
                p = j; q = k;
            }
        }
    }
    vis[p] = vis[q] = 1;
    for(int i = 3; i <= m; i++){
        int k;
        for(int j = 1; j <= n; j++){
            if(vis[j]) continue;
            k = j;
            break;
        }
        vis[k] = 1;
        for(int j = 1; j <= n; j++){
            if(vis[j]) continue;
            if((ans&a[j]) > (ans&a[k])){
                vis[k] = 0;
                k = j;
                vis[j] = 1;
            }
        }
        ans = (ans&a[k]);
    }
    cout << ans;
    return 0;
}
