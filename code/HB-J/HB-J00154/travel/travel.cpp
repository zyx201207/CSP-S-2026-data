#include<bits/stdc++.h>
using namespace std;
//only 01 and 016 is 1
string s1, t1, s2, t2;
string t, m;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> s1 >> t1 >> s2 >> t2;
    for(int i = 0;i<t1.length();i++) {
        t += t1[i];
    }
    for(int i = 0;i<=1;i++) {
        m += t2[i];
    }
    if(s1!=s2) {
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    else {
        cout << 1;
    }
    if(t != m) {
        cout << 0 << 0 << 0;
        return 0;
    }
    else{
        cout << 1;
    }
    if((t1[2] >= 'A' && t1[2] <= 'C' && t2[2] <= 'C' && t2[2] >= 'A') || (t1[2] >= 'F' && t1[2] <='E' && t2[2] >= 'F' && t2[2] <= 'E')) {
        cout << 1;
        if((abs)(t1[2] - t2[2]) == 1) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    else{
        cout << 0 << 0;
    }
}
