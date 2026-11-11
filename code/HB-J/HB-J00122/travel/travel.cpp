#include <bits/stdc++.h>

using namespace std;

string c1 , s1 , c2 , s2;
string t1 = "ABC" , t2 = "DF";

int main () {
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2)
        cout << "0000";
    else {
        if (s1[0] != s2[0] || s1[1] != s2[1])
            cout << "1000";
        else {
            int l1 = t1.find(s1[2]) , l2 = t1.find(s2[2]);
            int r1 = t2.find(s1[2]) , r2 = t2.find(s2[2]);
            if ((l1 != -1 && l2 != -1) || (r1 != -1 && r2 != -1)) {
                cout << "111";
                if (l1 != -1 && l2 != -1) {
                    if (abs(l1 - l2) == 1)
                        cout << "1";
                    else
                        cout << "0";
                }
                else
                    cout << "1";
            }
            else
                cout << "1100";
        }
    }
    return 0;
}