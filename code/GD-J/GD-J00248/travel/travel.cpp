#include <bits/stdc++.h>

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

#define fst first
#define snd second

using namespace std;
using ll = long long;
using ld = long double;
string s, t, a, b;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> s >> t >> a >> b;
    if (s != a) return cout << "0000", 0;
    cout << 1;
    if (t[0] != b[0] or t[1] != b[1]) return cout << "000", 0;
    cout << 1;
    if ((t[2] <= 'C') != (b[2] <= 'C')) return cout << "00", 0;
    cout << 1;
    if (llabs(t[2] - b[2]) > 1) return cout << 0, 0;
    cout << 1;
    return 0;
}