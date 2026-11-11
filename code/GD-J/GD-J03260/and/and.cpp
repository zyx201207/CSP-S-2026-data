#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;

bool cmp(int x, int y) {
    return x > y;
}

int n, m, a[200005], f[2][200005];

signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)     // O(n)
        cin >> a[i];

    sort(a + 1, a + 1 + n, cmp);     // O(nlogn)
    f[0][0] = a[1];

    for(int i = 1; i <= n; i++)         // O(nm)
        for(int j = 0; j <= m; j++) {
            if(j > i) f[i%2][j] = 0;
            else {
                f[i%2][j] = f[(i - 1)%2][j];
                if(j)
                    f[i%2][j] = max(f[i%2][j], f[(i - 1)%2][j - 1] & a[i]);
            }
        }
    cout << f[n%2][m];
    return 0;
}


// 50 
