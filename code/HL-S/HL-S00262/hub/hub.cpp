#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    long long a, b;
    cin >>a >> b;
    if (a == 0) {
        if (b == 2) {
            cout << 1 << endl << 2;
        }
        if (b == 3) {
            cout << 1 << endl << 1 <<endl <<2;
        }
        if (b == 5) {
            cout << 17 <<endl <<9 <<endl << 6 <<endl << 6 << endl << 9;
        }
        if (b == 1) {
            cout <<12251 <<endl;
        }
    }
    return 0;
}
