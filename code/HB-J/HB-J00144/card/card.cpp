#include <bits/stdc++.h>
using namespace std;
void open (string s) {
    string in = s + ".in", out = s + ".out";
    freopen (in.c_str(), "r", stdin);
    freopen (out.c_str(), "w", stdout);
}
typedef long long ll;
int n, m, a[1000100];
stack<int> stk, ept;
int book[300100], ans[1000100];
int main () {
    open ("card");
    cin >> n >> m;
    for (int k = 1; k <= m; ++k) {
        for (int i = 1 + k - 1; i <= n; ++i) {
            cin >> a[i];
            stk.push(a[i]);
            if (book[a[i]] > 0) {
                book[a[i]]++;
                do {
                    book[stk.top()]--;
                    stk.pop();
                } while(stk.top() == a[i]);
            } else {
                book[a[i]]++;
            }
        }
        for (int i = 1; i <= m; ++i) {
            if (book[i] > 0) {
                ans[i]++;
            }
        }
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << " ";
    return 0;
}
