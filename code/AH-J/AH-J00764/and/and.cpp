#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, m;
int a[N], f[N][N];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    memset(f, 0xff, sizeof f);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        for(int j = i; j <= n; j++){
            for(int k = i - 1; k < j; k++){
                f[i][j] = max(f[i][k], max(f[i][j], f[i - 1][k] & a[j]));
            }
        }
    }
    cout << f[m][n];
    return 0;
}
