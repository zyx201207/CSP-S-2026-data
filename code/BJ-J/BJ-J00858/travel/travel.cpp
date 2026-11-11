#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
string a, b, c, d;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> a >> b >> c >> d;
    if(a != c) cout << "0000";
    else {
        if(b[0] != d[0] || b[1] != d[1]) cout << "1000";
        else {
            int x = b[2] - 'A', y = d[2] - 'A';
            x ++ , y ++ ;
            if((x <= 3 && y >= 4) || (y <= 3 && x >= 4)) cout << "1100";
            else {
                if((x == 1 && y == 3) || (y == 1 && x == 3)) cout << "1110";
                else cout << "1111";
            }
        }
    }
    return 0;
}
