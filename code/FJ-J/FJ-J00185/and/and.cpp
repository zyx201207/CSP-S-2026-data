#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], w[maxn][32], s[32];
vector<int> x;
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        x.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int x = a[i], k = -1;
        while (x) {
            w[i][++k] = x % 2;
            x /= 2;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            s[j] += w[i][j];
        }
    }
    for (int i = 29; i >= 0; i--) {
        if (s[i] > m) {
            vector<int> temp;
            for (int j = 0; j < x.size(); j++) {
                if (w[x[j]][i]) {
                    temp.push_back(x[j]);
                }
            }
            x = temp;
            for (int i = 0; i < 30; i++) {
                s[i] = 0;
            }
            for (int i = 0; i < x.size(); i++) {
                for (int j = 0; j < 30; j++) {
                    s[j] += w[x[i]][j];
                }
            }
        }
        if (s[i] == m) {
            vector<int> temp;
            for (int j = 0; j < x.size(); j++) {
                if (w[x[j]][i]) {
                    temp.push_back(x[j]);
                }
            }
            x = temp;
            int ans = a[x[0]];
            for (int i = 1; i < x.size(); i++) {
                ans &= a[x[i]];
            }
            cout << ans;
            return 0;
        }
    }
    int ans = a[x[0]];
    for (int i = 1; i < m; i++) {
        ans &= a[x[i]];
    }
    cout << ans;
    return 0;
}