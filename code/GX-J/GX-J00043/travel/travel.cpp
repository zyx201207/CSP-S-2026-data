#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int x = 0, y = 0;
    string a, aa, b, bb;
    cin >> a >> aa >> b >> bb;
    for(int i = 0 ; i <= 1 ; i++){
        if(a[i] == b[i])
            x++;
        if(aa[i] == bb[i])
            y++;
    }if(x == 2) cout << 1;
    else {
        cout << "0000";
        return 0;
    }
    char c = aa[2];
    char d = bb[2];
    if(y == 2) cout << 1;
    else{
        cout << "000";
        return 0;
    }
    if(c == 'A' && d == 'B') cout << 11;
    else if(c == 'A' && d == 'C') cout << 10;
    else if(c == 'B' && d == 'A' || c == 'C') cout << 11;
    else if(c == 'C' && d == 'B') cout << 11;
    else if(c == 'C' && d == 'A') cout << 10;
    else if(c == 'D' && d == 'E') cout << 11;
    else if(c == 'E' && d == 'D') cout << 11;
    else if(d == 'A' && c == 'B') cout << 11;
    else if(d == 'A' && c == 'C') cout << 10;
    else if(d == 'B' && c == 'A' || c == 'C') cout << 11;
    else if(d == 'C' && c == 'B') cout << 11;
    else if(d == 'C' && c == 'A') cout << 10;
    else if(d == 'D' && c == 'E') cout << 11;
    else if(d == 'E' && c == 'D') cout << 11;
    else cout << 0;
    cout << c << d;
    return 0;
}
