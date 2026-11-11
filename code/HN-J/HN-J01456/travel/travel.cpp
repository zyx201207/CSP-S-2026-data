#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define sqr(x) ((x) * (x))
using namespace std;

void solve() {
    int a, b, c, d;
    char c1, c2;
    cin >> a >> b >> c1 >> c >> d >> c2;
    auto find = [&](char ch) -> int {
        if (ch == 'A' || ch == 'B' || ch == 'C')
            return 1;
        if (ch == 'D' || ch == 'F')
            return 2;
        return 0;
    };
    if (a != c)
        cout << "0000\n";
    else {
        cout << 1;
        if (b != d)
            cout << "000\n";
        else {
            cout << 1;
            if (find(c1) != find(c2))
                cout << "00\n";
            else {
                cout << 1;
                if ((c1 == 'A' &&c2 == 'B') || (c1 == 'B' &&c2 == 'A') || (c1 == 'C' &&c2 == 'B') || (c1 == 'B' &&c2 == 'C') || (c1 == 'D' &&c2 == 'F') || (c1 == 'F' &&c2 == 'D'))
                    cout << "1\n";
                else
                    cout << "0\n";
            }
        }
    }
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int oT_To = 1;
    // cin >> oT_To;
    while (oT_To --)
        solve();
    return 0;
}
