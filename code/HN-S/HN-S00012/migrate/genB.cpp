#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e6 + 5;
int n;
ll x[MAXN];

int rnd(int l, int r) {
    return rand() % (r - l + 1) + l;
}

void makedata(int n) {
    cout << n << ' ';
    int pos = rnd(n / 2 - 50, n / 2 + 50);
    x[0] = -1e18;
    for (int i = 1; i <= n; ++i) {
        x[i] = x[i - 1] + rnd(1, 9e3);
    }
    cout << max(llabs(x[pos] - x[1]), llabs(x[n] - x[pos])) + rnd(0, 1e4) << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << x[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));

    int c = 13, t = 10;
    cout << c << ' ' << t << '\n';
    while (t--) makedata(300);
}