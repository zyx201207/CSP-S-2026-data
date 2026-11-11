#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans[300011], cnt[500011];
int n, m, a[500011], pos[500011], last[300011];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    memset(ans, 0, sizeof(ans));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    memset(last, 0, sizeof(last));
    for(int i = n; i > 0; i--) {
        if(last[a[i]])
            pos[i] = pos[last[a[i]]];
        else 
            pos[i] = i + 1;
        last[a[i]] = i;
    }
    for(int i = 1; i <= n; i++)
        cnt[i] = 1;
    for(int i = 1; i <= n; i++) {
        ans[a[i]] += cnt[i];
        cnt[pos[i]] += cnt[i];
    }
    ans[a[n]] = n;
    for(int i = 1; i <= m; i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}