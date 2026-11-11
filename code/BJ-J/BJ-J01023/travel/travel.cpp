#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    
    int r, x, ri = 0, xi = 0; string rs, xs; char rs2, xs2;
    cin >> r >> rs >> x >> xs;
    bool rb= false, xb = false;
    ri += (int)rs[1] - '0'; xi = (int)xs[1] - '0';
    rs2 = rs[2]; xs2 = xs[2];
    if (((int)(rs2) >= 'A' && (int)(rs2) <= 'C' && (int)(xs2) >= 'A' && (int)(xs2) <= 'C') || ((int)(rs2) >= 'D' && (int)(rs2) <= 'F' && (int)(xs2) >= 'D' && (int)(xs2) <= 'F')) {
        rb = true;
    } if (abs((int)(rs2) - (int)(xs2)) == 1 && rb && r == x && ri == xi) xb = true;
    cout << ((r == x) ? 1 : 0) << ((r == x && ri == xi) ? 1 : 0) << ((r == x && ri == xi && rb) ? 1 : 0) << (xb ? 1 : 0);
}