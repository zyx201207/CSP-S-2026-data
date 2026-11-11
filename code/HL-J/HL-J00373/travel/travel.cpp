#include <iostream>
using namespace std;

int c1, c2, s1A, s2A;
char s1B, s2B;
string s1, s2;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> c1 >> s1 >> c2 >> s2;
    s1A = (s1[0] - '0') * 10 + (s1[1] - '0'), s1B = s1[2];
    s2A = (s2[0] - '0') * 10 + (s2[1] - '0'), s2B = s2[2];
    if (c1 == c2) {
        cout << 1;
        if (s1A == s2A) {
            cout << 1;
            if ((string("ABC").find(s1B) != string::npos && string("ABC").find(s2B) != string::npos) || (string("DF").find(s1B) != string::npos && string("DF").find(s2B) != string::npos)) {
                cout << 1;
                if (min(s1B, s2B) + 1 == max(s1B, s2B) || min(s1B, s2B) == 'D' && max(s1B, s2B) == 'F') cout << 1;
                else cout << 0;
            } else cout << "00";
        } else cout << "000";
    } else cout << "0000";
    return 0;
}
