#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a, sa, b, sb;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> sa >> b >> sb;
    if (a != b) cout << "0000";
    else {
        cout << "1";
        string tempa = "", tempb = "";
        tempa += sa[0];
        tempa += sa[1];
        tempb += sb[0];
        tempb += sb[1];
        if (tempa != tempb) cout << "000";
        else {
            cout << "1";
            if (sa[2] == 'A') {
                if (sb[2] == 'B') cout << "11";
                else if (sb[2] == 'C') cout << "10";
                else cout << "00";
            } else if (sa[2] == 'B') {
                if (sb[2] == 'A' || sb[2] == 'C') cout << "11";
                //else if (sb[2] == 'C') cout << "10";
                else cout << "00";
            } else if (sa[2] == 'C') {
                if (sb[2] == 'B') cout << "11";
                else if (sb[2] == 'A') cout << "10";
                else cout << "00";
            } else if (sa[2] == 'D') {
                if (sb[2] == 'F') cout << "11";
                //else if (sb[2] == 'C') cout << "10";
                else cout << "00";
            }
        }
    }
    return 0;
}
