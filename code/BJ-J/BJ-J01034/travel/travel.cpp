#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int r, rr, x, xx, rrr, xxx;
    char s, ss;
    cin >> r >> rr >> s >> x >> xx >> ss;
    if(r == x) cout << 1;
    else
    {
        cout << 0;
        cout << 0;
        cout << 0;
        cout << 0;
        return 0;
    }
    if(rr == xx) cout << 1;
    else
    {
        cout << 0;
        cout << 0;
        cout << 0;
        return 0;
    }
    if(s == 'A' || s == 'B' || s == 'C') rrr = 0;
    else rrr = 1;
    if(ss == 'A' || ss == 'B' || ss == 'C') xxx = 0;
    else xxx = 1;
    if(rrr == xxx)
    {
        cout << 1;
        if(s - ss == 1 || s - ss == -1) cout << 1;
        else cout << 0;
    }
    else
    {
        cout << 0;
        cout << 0;
    }
    return 0;
}