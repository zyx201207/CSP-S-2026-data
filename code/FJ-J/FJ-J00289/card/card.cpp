#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 5;
const int maxm = 3e5 + 5;

int n, m;
int a[maxn], ans[maxm], nxt[maxn], lst[maxm];

signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    memset(nxt, -1, sizeof(nxt));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];   
        if (lst[a[i]]) {
            nxt[lst[a[i]]] = i;
        }
        lst[a[i]] = i;
    }
    for (int t = 1; t <= n; ++t) {
        for (int i = t; i <= n; ) {
            if (nxt[i] == -1) {
                ++ans[a[i]];              
                ++i;
            } else {
                i = nxt[i];
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
/*
思路：
预处理出每一个点往后第一个与它相同的点记为nxt[i]
显然[i,nxt[i]-1]的数一定不能要，跳过即可
如果没有记nxt[i]=-1
显然的，被包起来的数不会被考虑到
那么nxt[i]=-1的数对有贡献
 4 3
1 2 1 3
*/
