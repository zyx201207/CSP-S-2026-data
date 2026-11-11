#include <bits/stdc++.h>
using namespace std;
long long a[550000], pre[550000];
bool cmp(int a, int b) {
    if(a < 0) {
        return a < b;
    }
    if(b < 0) {
        return b < a;
    }
    if(a < 0 && b < 0) {
        return abs(a) > abs(b);
    }
    return a < b;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    pre[1] = a[1];
    for(int i = 2 ; i <= n ; i++) {
        pre[i] = abs(a[i] - a[i - 1]);
    }
    long long ans = 0, cnt = 0, maxn = 0;
    pre[1] = 0;
    for(int i = 1 ; i <= n ; i++) {
        ans = ans + pre[i];
        if(ans <= m) {
            cnt++;
        } else {
            ans = 0;
            cnt = 0;
        }
        maxn = max(cnt, maxn);
    }
    cout << maxn << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
