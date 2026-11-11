#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, b, x, y;
    cin >> a >> x >> b >> y;
    if (a == b){
        cout << "1";
        if (x.substr(0, 2) == y.substr(0, 2)){
            cout << "1";
            if ((x[2] == 'D' || x[2] == 'F') == (y[2] == 'D' || y[2] == 'F')){
                cout << "1";
                if ((x[2] == 'D' || x[2] == 'F') && (y[2] == 'D' || y[2] == 'F'))
                    cout << "1\n";
                else if ((x[2] == 'A' && y[2] == 'B') || (x[2] == 'B' && y[2] == 'A') ||
                         (x[2] == 'C' && y[2] == 'B') || (x[2] == 'B' && y[2] == 'C'))
                    cout << "1\n";
                else
                    cout << "0\n";
            }
            else
                cout << "00\n";
        }
        else
            cout << "000\n";
    }
    else
        cout << "0000\n";
    return 0;
}
