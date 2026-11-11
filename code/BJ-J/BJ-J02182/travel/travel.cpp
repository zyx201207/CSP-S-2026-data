#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    //int ans1 = 1, ans2 = 1, ans3 = 1, ans4 = 1;
    for (int i = 0; i < c1.size(); i++) {
        if (c1[i] != c2[i]) {
            cout << "0000";
            return 0;
        }
    }
    for (int i = 0; i < s1.size() - 1; i++) {
        if (s1[i] != s2[i]) {
            cout << "1000";
            return 0;
        }
    }
    if (s1[2] <= 'C' && s1[2] >= 'A' && s2[2] <= 'C' && s2[2] >= 'A' || 
        s1[2] <= 'F' && s1[2] >= 'D' && s2[2] <= 'F' && s2[2] >= 'D' ) {
        if(s1[2] - 1 == s2[2] || s1[2] + 1 == s2[2]) {
            cout << "1111";
        } else {
            cout << "1110";
        }
    } else {
        cout << "1100";
    }
    return 0;
}