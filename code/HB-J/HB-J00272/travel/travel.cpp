#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << x << '\n';

using namespace std;

void solve()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    bool t1 = (a == c);
    if (t1) {
        cout << 1;
    } else {
        cout << 0;
    }
    bool t2 = (t1 && b[0] == d[0] && b[1] == d[1]);
    if (t2) {
        cout << 1;
    } else
        cout << 0;
    bool t3 = (b[2] <= 'C' && d[2] <= 'C' || b[2] > 'C' && d[2] > 'C');
    t3 &= t2;
    if (t3) {
        cout << 1;
    } else
        cout << 0;
    bool tt4 = (b[2] == 'C' && d[2] == 'D');
    tt4 |= (b[2] == 'D' && d[2] == 'C');
    bool t4 = (abs(b[2] - d[2]) == 1 && t3 && !tt4);
    if (t4) {
        cout << 1;
    } else
        cout << 0;
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}