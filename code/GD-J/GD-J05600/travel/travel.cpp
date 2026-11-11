#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int a, c;
    string b, d;
    bool x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    cin >> a >> b >> c >> d;
    int a1 = (b[0] - '0') * 10 + (b[1] - '0'), c1 = (d[0] - '0') * 10 + (d[1] - '0');
    if(a == c) x1 = 1;
    if(x1 && a1 == c1) x2 = 1;
    if(x1 && x2){
        if(b[2] <= 'C' && d[2] <= 'C') x3 = 1;
        if(b[2] >= 'D' && d[2] >= 'D') x3 = 1;
    }
    if(x1 && x2 && x3 && abs(b[2] - d[2]) == 1) x4 = 1;
    cout << x1 << x2 << x3 << x4;
    return 0;
}

