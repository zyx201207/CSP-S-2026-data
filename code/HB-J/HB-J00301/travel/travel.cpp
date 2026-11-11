#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main(int argc,char* argv[]) {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;

    if (c1 == c2) {
        cout << 1;
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            cout << 1;
            bool sd1,sd2;
            if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
                sd1 = 0;
            }
            else {
                sd1 = 1;
            }
            if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
                sd2 = 0;
            }
            else {
                sd2 = 1;
            }
            if (sd1 == sd2) {
                cout << 1;
                if (s1[2] + 1 == s2[2] || s2[2] + 1 == s1[2]) {
                    cout << 1;
                }
                else cout << "0";
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";

    // It definitely can bring me 100.
    // I never worry about question 1.
    // If I get good grades in this contest, I will try Senior Grade next year.
    // I calculated my score, and that is my answer:
    // Q 1  Q 2  Q 3  Q 4 Total Avg
    // 100  72   16   16  204   51

    return EXIT_SUCCESS;
}
