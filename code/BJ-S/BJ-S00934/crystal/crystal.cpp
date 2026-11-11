#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 7;
int n;
long long m;
long long a[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;bool flag = true;
    for(int i = 1; i <= n; i++) {cin >> a[i];
        if(a[i] != 1 && a[i] != a[i - 1]) flag = false;
    }if(flag) {cout << n;return 0;}
    sort(a + 1, a + n + 1);int ans = 0;
    for(int i = n; i >= 2; i--) {
        if(i < n && a[i] == a[i + 1]) continue;
        long long need = 0;flag = true;
        for(int j = i - 1; j >= 1; j--) {
            need += a[i] - a[j];
            if(need > m) {ans = max(ans, i - j);break;}
            if(j > 1 && need + a[i] - a[j - 1] > m) {
                ans = max(ans, i - j + 1);break;
            }if(j == 1 && need <= m) {ans = max(ans, i);flag = false;}
        }if(flag == false) break;
    }
    cout << ans;
    return 0;
}
