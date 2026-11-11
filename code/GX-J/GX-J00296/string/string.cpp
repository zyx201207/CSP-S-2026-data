#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n, ans = 0;
    long long a[500005];
    char c[500005];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> c[i];
        ans += a[i];
    char s[ans + 5];
    for (int i = 1; i <= n; i++) {
        int d = 0;
        for (int j = 1; j <= a[i]; j++) {
            s[d] = c[i];
            d++;
        }
        int cnt = 0;
        for (int i = 1; i <= cnt / 2; i++) {
            if (s[i] = s[ans - i + 1])
                cnt++;
            else
                cnt += 0;
        }
        cout << cnt;
    }
    return 0;
}
