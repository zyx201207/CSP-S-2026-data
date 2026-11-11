
#include <iostream>
#include <cmath>

using namespace std;

int main () {

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int c1 = 0;
    string s1 = "";
    int c2 = 0;
    string s2 = "";

    cin >> c1 >> s1 >> c2 >> s2;

    bool res1 = 0;
    bool res2 = 0;
    bool res3 = 0;
    bool res4 = 0;

    if (c1 == c2) {
        res1 = 1;
    }
    string a = "";//1
    string b = "";//2
    a = s1[0] + s1[1];//pai
    b = s2[0] + s2[1];//pai

    if (a == b && res1) {
        res2 = 1;
    }
    char c, d;
    c = s1[2];
    d = s2[2];//zuowei
    if (res2 && ((c <= 'C' && d <= 'C') || (c >= 'D' && d >= 'D'))) {
        res3 = 1;
    }
    if ((abs(int(c) - int(d)) == 1 || (c == 'D' && d == 'F' || c == 'F' && d == 'D')) && res3) {
        res4 = 1;
    }

    cout << res1;
    cout << res2;
    cout << res3;
    cout << res4 << endl;
    return 0;
}