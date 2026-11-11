#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    static int sgn, res; sgn = 0, res = 0; static char ch = getchar();
    while(!isdigit(ch)) sgn ^= (ch == '-'), ch = getchar();
    while(isdigit(ch)) res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
    return sgn ? -res : res;
}

const int N = 2e5 + 10, NN = 2000 + 10;
int n, m, a[N], f[NN][NN];

struct Num{
    int v, c;

    bool operator<(const Num &C) const{
        return C.c < c;
    }
}b[N];

bool cmp(int x, int y){
    return x > y;
}

signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    if(n == 1){
        cout << *max_element(a + 1, a + 1 + n);
        return 0;
    }
    if(n > 2000 && n <= 2e5){
        int c[N], ans = 0;
        for(int i = 1; i <= n; i++){
            b[i].v = a[i];
            b[i].c = log2(a[i] + 1);
        }
        sort(b + 1, b + 1 + n);
        ans = b[1].v;
        for(int i = 2; i <= m; i++)
            ans &= b[i].v;
        cout << ans;
        return 0;
    }
    for(int i = 1; i <= n; i++) f[i][1] = a[i];
    for(int i = 1; i <= n; i++){
        for(int j = 2; j <= m; j++){
            f[i][j] = f[i - 1][j];
            for(int k = 1; k < i; k++){
                f[i][j] = max(f[i][j], f[k][j - 1] & a[i]);
            }
        }
    }
    cout << f[n][m];
    return 0;
}