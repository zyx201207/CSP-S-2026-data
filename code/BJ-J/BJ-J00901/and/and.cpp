#include <iostream>
using namespace std;
#define int long long
int a[200010];
int p2[50], flag[200010][40];
int vis[200010];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    p2[0] = 1;
    for(int j = 1; j <= 30; ++j)
        p2[j] = p2[j - 1] * 2;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        int x = a[i];
        for(int j = 30; j >= 0; --j)
            if(x - p2[j] >= 0) {
                flag[i][j] = 1;
                x -= p2[j];
            }
    }
    int ans = 0;
    for(int j = 30; j >= 0; --j) {
        int sum = 0;
        for(int i = 1; i <= n; ++i)
            if(!vis[i] && flag[i][j]) sum++;
        if(sum >= m) {
            for(int i = 1; i <= n; ++i)
                if(!vis[i] && !flag[i][j]) vis[i] = 1;
            ans += p2[j];
        }
    }
    cout << ans << endl;
    return 0;
}
