#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    static int sgn, res; sgn = 0, res = 0; static char ch = getchar();
    while(!isdigit(ch)) sgn ^= (ch == '-'), ch = getchar();
    while(isdigit(ch)) res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
    return sgn ? -res : res;
}

const int N = 5e5 + 10;
int n, m, a[N], nxt[N], ans[N], f[N];

signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        for(int j = n; j >= i; j--)
            if(a[i] == a[j]){
                nxt[i] = j;
                break;
            }
    for(int i = 1; i <= n; i++){
        int p = i;
        while(p <= n){
            ans[a[p]]++;
            p = nxt[p] + 1;
        }
    }
    for(int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
    return 0;
}