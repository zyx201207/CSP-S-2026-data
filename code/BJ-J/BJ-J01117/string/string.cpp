#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, sum = 0;
int num[200010];
char c[200010];

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i] >> c[i];
    }
    int idxl = 1, idxr = n;
    while (idxl <= idxr) {
        int cnt = abs(num[idxl] - num[idxr]);
        if (c[idxl] == c[idxr]) {
            if (cnt == 0) {
                idxl++;
                idxr--;
                continue;
            } else {
                if (num[idxl] > num[idxr]) {
                    idxr--;
                    num[idxl] = cnt;
                } else {
                    idxl++;
                    num[idxr] = cnt;
                }
            }
        } else {
            sum += min(num[idxl], num[idxr]);
            if (cnt != 0) {
                if (num[idxl] > num[idxr]) {
                    idxr--;
                    num[idxl] = cnt;
                } else {
                    idxl++;
                    num[idxr] = cnt;
                }
            } else {
                idxl++;
                idxr--;
            }
        }
    }
    cout << sum << '\n';
    return 0;
}
