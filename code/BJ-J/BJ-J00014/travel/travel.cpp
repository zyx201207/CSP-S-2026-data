#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    char x = s1[2], y = s2[2];
    bool b1 = false, b2 = false;
    cout << (c1 == c2);
    cout << (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]);
    if(x == 'A' || x == 'B' || x == 'C') {
        if (y == 'A' || y == 'B' || y == 'C') b1 = true;
        else b1 = false;
    }
    else {
        if(x == 'D' || x == 'E') {
            if(y == 'D' || y == 'E') b1 = true;
            else b1 = false;
        }
    }
    cout << (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && b1);
    if(x == 'A') {
        if (y == 'B') b2 = true;
        else b2 = false;
    }
    else if(x == 'B') {
        if (y == 'A' || y == 'C') b2 = true;
        else b2 = false;
    }
    else if(x == 'C') {
        if (y == 'B') b2 = true;
        else b2 = false;
    }
    else if(x == 'D') {
        if (y == 'E') b2 = true;
        else b2 = false;
    }
    else {
        if(y == 'D') b2 = true;
        else b2 = false;
    }
    cout << (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && b1 && b2);
    return 0;
}