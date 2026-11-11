#include <bits/stdc++.h>
using namespace std;

const int MxN = 500005, MxM = 300005;
int n, m, a[MxN], ans[MxM];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    if (n > 500) {
        for (int i = 1; i <= n; i++) {
            ans[a[i]] = max(ans[a[i]], i);
        }
    } else {
        for (int t = 1; t <= n; t++) {
            int lst[MxM] = {0};
            int pai[MxN], pt = 0;
            for (int i = t; i <= n; i++) {
                pai[++pt] = a[i];
                if (lst[a[i]]) {
                    for (int j = lst[a[i]]; j < i - t + 1; j++) {
                        lst[pai[j]] = 0;
                        pai[j] = 0;
                    }
                }
                lst[a[i]] = i - t + 1;
                //for (int j = 1; j <= pt; j++) cout << pai[j] << ' ';
                //cout << endl;
            }//cout << "@\n";
            bool tmp[m] = {0};
            for (int i = 1; i <= pt; i++) {
                if (!tmp[pai[i]]) {
                    ans[pai[i]]++;
                    tmp[pai[i]] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}