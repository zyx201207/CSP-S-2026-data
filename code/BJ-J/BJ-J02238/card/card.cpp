#include <bits/stdc++.h>
using namespace std;
long long n, m;
int a[500005], temp[500005], zz, ans[300005], tong[300005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for(int i = n; i > 0; i--) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
            zz = 0;
        for(int j = 1; j <= i; j++) {
            if(tong[a[j]]) {
                while(temp[zz] != a[j]) {
                    tong[temp[zz]]--;
                    temp[zz] = 0;
                    zz++;
                }
            }
            tong[a[j]]++;
            temp[j] = a[j];
        }
        for(int j = 1; j <= m; j++) {
            if(tong[j]) {
                ans[j]++;
            }
            tong[j] = 0;
        }
    }
    for(int i = 1; i <= m; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
