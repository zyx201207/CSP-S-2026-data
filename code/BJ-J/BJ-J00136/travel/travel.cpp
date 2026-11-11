#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
long long e[8] = {0, 1, 1, 1, 2, 2, 2}, f[8] = {0, 1, 2, 3, 5, 0, 6};
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c >> d;
    if (a.compare(c) == 0){
        cout << '1';
        if (b[0] == d[0] && b[1] == d[1]){
            cout << '1';
            if (e[b[2] - 64] == e[d[2] - 64])
                cout << '1';
            else cout << '0';
            if (abs(f[b[2] - 64] - f[d[2] - 64]) == 1)
                cout << '1';
            else cout << '0';
        } else cout << "000";
    } else cout << "0000";
    return 0;
}
