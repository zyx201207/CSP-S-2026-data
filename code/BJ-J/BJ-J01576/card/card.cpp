#include <bits/stdc++.h>
using namespace std;
int n, m, a[500010];
int ccnt[300010], ans[300010];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        memset(ccnt, 0, sizeof(ccnt));
        for(int j = i; j <= n; j++) {
            for(int k = n; k >= j + 1; k--) {
                if(a[k] == a[j]) {
                    j = k;
                }
            }
            ccnt[a[j]] = 1;
        }
        for(int i = 1; i <= m; i++) {
            ans[i] += ccnt[i];
        }
    }
    for(int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
