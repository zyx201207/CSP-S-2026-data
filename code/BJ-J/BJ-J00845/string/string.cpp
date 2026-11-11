#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2E5 + 500;
string tot;
int n;
int main () {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        char c;
        cin >> a >> c;
        for (int i = 1; i <= a; i++) {
            tot += c;
        }
    }
    if (tot.size() % 2 == 0) {
        string _tot = "", tot_ = "";
        for (int i = 0; i < tot.size() / 2; i++) {
            _tot += tot[i];
        }
        for (int i = tot.size() / 2; i < tot.size(); i++) {
            tot_ += tot[i];
        }
        tot = _tot;
        tot += '#';
        tot += tot_;
        //cout << tot << ' ' << _tot << ' ' << tot_ << endl;
    }
    int pos = tot.size() / 2;
    int sum = 0;
    for (int i = 1; i <= tot.size(); i++) {
        if (tot[pos - i] != tot[pos + i]) {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
