#include <iostream>
#include <fstream>
using namespace std;
int n, a[200003];
long long ans;
char c[200003];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    int l = 1, r = n;
    while (l <= r) {
        if (a[l] < a[r]) {
            if (c[l] != c[r]) {
               ans += a[l];
            }
            a[r] -= a[l];
            l++;
        } else if (a[l] > a[r]) {
            if (c[l] != c[r]) {
                ans += a[r];
            }
            a[l] -= a[r];
            r--;
        } else {
            if (c[l] != c[r]) {
                ans += a[l];
            }
            l++;
            r--;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
