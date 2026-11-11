#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = 0, temp = 2147483647;
int a[200005];
void dfs(long long step, long long num) {
    if(step > m) {
        ans = max(ans, temp);
        cout << temp << endl;
        return ;
    }
    temp = temp & a[num];
    for(int i = num + 1; i < n; i++) {
        dfs(step + 1, i);
    }
    return ;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        ans = max(ans, (long long)a[i]);
    }
    if(m == 1) {
        printf("%lld\n", ans);
        return 0;
    }
    if(m == n) {
        ans = a[0];
        for(int i = 1; i < n; i++) {
            ans = ans & a[i];
        }
        printf("%lld\n", ans);
        return 0;
    }
    if(m == 2) {
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                ans = max(ans, (long long)(a[i] & a[j]));
            }
        }
        return 0;
    }
    ans = 0;
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}
