#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int ans = -1;

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int a[N], f[N][N];
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    f[1][1] = a[1];
    for(int i = 1; i <= n; i++)
        f[i][1] = max(f[i-1][1], a[i]);
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= m; j++)
            f[i][j] = max(f[i-1][j], f[i-1][j-1] & a[i]);
    for(int i = 1; i <= n; i++)
        ans = max(ans, f[i][m]);
    cout << ans << '\n';
    return 0;
}
