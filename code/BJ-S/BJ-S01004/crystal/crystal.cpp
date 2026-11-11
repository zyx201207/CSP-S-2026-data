#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int n, ans = 0;
long long m, a[500002], c[500002], s[500002];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        c[i] = a[i] - a[i - 1];
    }
    for (int i = 2; i <= n; i++) {
        s[i] = i - 1;     //MOV [s + i], i - 1
        if (c[i] > m / (i - 1) + 1) {
            ans = i - 1;
            break;
        }
        s[i] *= c[i];     //MUL [s + i], [c + i]
        if (s[i - 1] > m - s[i]) {
            ans = i - 1;
            break;
        }
        s[i] += s[i - 1]; //ADD [s + i], [a + i - 1]
        if (s[i] > m) {
            ans = i - 1;
            break;
        }
    }
    //s[i] = sum(:in(j)(:from = 1, :to = i), :do(d[i][j])) = add(mul(i - 1, c[i]), s[i - 1])
    //for (int i = 1; i <= n; i++) cout << s[i] << " ";
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
