#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    /* Note: c1 is R's train num, s1 is R's seat num
     c2 is X's train num, s2 us X's seat num
    */
    if (c1 != c2) {
        cout << "0000" << endl;
        return 0;
    }
    else {
        if (s1[0] != s2[0] || s1[1] != s2[1]) {
            cout << "1000" << endl;
            return 0;
        }
        else {
            int num1 = s1[2] - 'A', num2 = s2[2] - 'A';
            /* Num {1,2} is number 0-4
             representing A-F
            */
            if (num1 > 2) {
                if (num2 > 2) {
                    cout << "1111" << endl;
                    return 0;
                }
            }
            else if (num1 <= 2) {
                if (num2 <= 2) {
                    if (num1 + 1 == num2 || num2 + 1 == num1) {
                        cout << "1111" << endl;
                        return 0;
                    }
                    else {
                        cout << "1110" << endl;
                        return 0;
                    }
                }
                else {
                    cout << "1100" << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}